#include "../inc/pathfinder.h"

enum line_status {ISLAND1, ISLAND2, BRIDGE};

int **errors(int argc, char* argv[], char ***name_islands, int *size) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(-1);
    }

    int file_name = open(argv[1], O_RDONLY);
    if (file_name <= 0) {
        char *err = NULL;
        err = mx_strjoin(err, "error: file ");                    
        err = mx_strjoin(err, argv[1]);
        err = mx_strjoin(err, " does not exist\n");
        mx_printerr(err);
        mx_strdel(&err);
        exit(-1);
    }

    char *c = malloc(1);
    if((read(file_name, c, 1)) <= 0) {
        char *err = NULL;
        err = mx_strjoin(err, "error: file ");                    
        err = mx_strjoin(err, argv[1]);
        err = mx_strjoin(err, " is empty\n");
        mx_printerr(err);
        mx_strdel(&err);
        exit(-1);
    }
    close(file_name);
    char *file = mx_file_to_str(argv[1]);
    bool first_line = true;
    char *char_num_of_islands = NULL;
    int num_of_islands = 0;
    int line = ISLAND1;
    int count = 2;
    char *island1 = NULL, *island2 = NULL;

    int len = mx_strlen(file);
    
    for (int index = 0; index < mx_strlen(file); index++) {
        c[0] = file[index];
        if (first_line) {
            if (mx_isdigit(file[index])) {
                char_num_of_islands = mx_strjoin(char_num_of_islands, c);
            }
            else if (file[index] == '\n' && char_num_of_islands != NULL) {
                first_line = false;
                num_of_islands = mx_atoi(char_num_of_islands);
                if (num_of_islands == 0) {
                    mx_printerr("error: line 1 is not valid\n");
                    exit(-1);
                }
                continue;
            } 
            else {
                mx_printerr("error: line 1 is not valid\n");
                exit(-1);
            }
        } 
        else {  
            if (mx_isalpha(file[index]) && (line == ISLAND1 || line == ISLAND2)) {
                if (line == ISLAND1)
                    island1 = mx_strjoin(island1, c);
                if (line == ISLAND2)
                    island2 = mx_strjoin(island2, c);
            }
            else if (mx_isdigit(file[index]) && line == BRIDGE) {    
                continue;
            }
            else if (file[index] == '-' && line == ISLAND1) {
                line = ISLAND2;
            }
            else if (file[index] == ',' && line == ISLAND2) {
                line = BRIDGE;
            }
            else if (file[index] == '\n' && line == BRIDGE) {
                line = ISLAND1;
                if (mx_strcmp(island1, island2) == 0) {
                    char *err = NULL;
                    err = mx_strjoin(err, "error: line ");                    
                    err = mx_strjoin(err, mx_itoa(count));
                    err = mx_strjoin(err, " is not valid\n");
                    mx_printerr(err);

                    mx_strdel(&err);
                    mx_strdel(&island1);
                    mx_strdel(&island2);

                    exit(-1);
                    
                }
                mx_strdel(&island1);
                mx_strdel(&island2);
                count++;
            }
            else {
                char *err = "error: line ";
                err = mx_strjoin(err, mx_itoa(count));
                err = mx_strjoin(err, " is not valid\n");
                mx_printerr(err);
                
                mx_strdel(&err);
                mx_strdel(&island1);
                mx_strdel(&island2);

                exit(-1);
            }
        }
    }
    if (file[len - 1] != '\n') {
        char *err = "error: line ";
        err = mx_strjoin(err, mx_itoa(count));
        err = mx_strjoin(err, " is not valid\n");
        mx_printerr(err);
        
        mx_strdel(&err);
        mx_strdel(&island1);
        mx_strdel(&island2);

        exit(-1);
    }
    char **islands = malloc((num_of_islands + 1) * sizeof(char **));
    for (int i = 0; i < num_of_islands; i++) {
        islands[i] = mx_strnew(1);
    }
    islands[num_of_islands] = NULL;
    count = 0;
    line = ISLAND1;

    for (int index = 0; index < mx_strlen(file); index++) {        
        c[0] = file[index];
        if (mx_isalpha(file[index]) && (line == ISLAND1 || line == ISLAND2)) {
            island1 = mx_strjoin(island1, c);
        }
        else if (mx_isdigit(file[index]) && line == BRIDGE) 
                continue;
        else if (file[index] == '-' && line == ISLAND1) {
            line = ISLAND2;
            bool unic = true;
            for (int i = 0; i < num_of_islands; i++) {
                if (mx_strcmp(islands[i], island1) == 0) {
                    unic = false;
                    break;
                }
            } 
            if (unic) {
                if (count >= num_of_islands) {
                    mx_strdel(&island1);
                    mx_del_strarr(&islands);
                    mx_printerr("error: invalid number of islands\n");
                    exit(-1);
                }
                islands[count] = mx_realloc(islands[count], mx_strlen(island1));
                islands[count] = mx_strcpy(islands[count], island1);
                count++;
            } 
            if (island1 != NULL)
                mx_strdel(&island1);            
        }
        else if (file[index] == ',' && line == ISLAND2) {
            line = BRIDGE;
            bool unic = true;
            for (int i = 0; i < num_of_islands; i++) {
                if (mx_strcmp(islands[i], island1) == 0) {
                    unic = false;
                    break;
                }
            } 
            if (unic) {
                if (count >= num_of_islands) {
                    mx_strdel(&island1);
                    mx_del_strarr(&islands);
                    mx_printerr("error: invalid number of islands\n");
                    exit(-1);
                }
                islands[count] = mx_realloc(islands[count], mx_strlen(island1));
                islands[count] = mx_strcpy(islands[count], island1);
                count++;
            } 
            if (island1 != NULL)
                mx_strdel(&island1);    
        }
        else if (file[index] == '\n' && line == BRIDGE) {
            line = ISLAND1;
        }
    }
    if (count != num_of_islands) {
        mx_strdel(&island1);
        mx_del_strarr(&islands);
        mx_printerr("error: invalid number of islands\n");
        exit(-1);
    }
    int **bridges = malloc(num_of_islands * sizeof(int **));
    for (int i = 0; i < num_of_islands; i++) {
        bridges[i] = malloc(sizeof(int *) * num_of_islands);
        for (int j = 0; j < num_of_islands; j++) {                    
            bridges[i][j] = 0;
        }
    }
    island1 = NULL; island2 = NULL; 
    char *temp_bridge = NULL;
    line = ISLAND1;
    long long sum = 0;
    for (int index = 0; index < mx_strlen(file); index++) {     
        c[0] = file[index];
        if (mx_isalpha(file[index]) && (line == ISLAND1 || line == ISLAND2)) {
            if (line == ISLAND1)
                island1 = mx_strjoin(island1, c);
            if (line == ISLAND2)
                island2 = mx_strjoin(island2, c);
        }
        else if (mx_isdigit(file[index]) && line == BRIDGE) 
            temp_bridge = mx_strjoin(temp_bridge, c);
        else if (file[index] == '-' && line == ISLAND1) {
            line = ISLAND2;
        }
        else if (file[index] == ',' && line == ISLAND2) {
            line = BRIDGE;
        }
        else if (file[index] == '\n' && line == BRIDGE) {
            line = ISLAND1;
            
            int first, second;
            for (int i = 0; i < num_of_islands; i++) {
                if (mx_strcmp(islands[i], island1) == 0) 
                    first = i;
                if (mx_strcmp(islands[i], island2) == 0) 
                    second = i;                
            }

            if (bridges[first][second] != 0) {
                mx_strdel(&island1);
                mx_strdel(&island2);
                mx_strdel(&temp_bridge);
                mx_del_strarr(&islands);
                for (int i = 0; i < num_of_islands; i++) {
                    free(bridges[i]);
                }
                free(bridges);
                mx_printerr("error: duplicate bridges\n");
                exit(-1);
            }
            else {
                if (sum <= 2147483647)
                    sum += mx_atoi(temp_bridge);
                
                bridges[first][second] = mx_atoi(temp_bridge);
                bridges[second][first] = mx_atoi(temp_bridge);;
            }
            mx_strdel(&island1);
            mx_strdel(&island2);
            mx_strdel(&temp_bridge);
        }
    }
    if (sum > 2147483647) {
        mx_strdel(&island1);
        mx_strdel(&island2);
        mx_strdel(&temp_bridge);
        mx_del_strarr(&islands);
        for (int i = 0; i < num_of_islands; i++) {
            free(bridges[i]);
        }
        free(bridges);
        mx_printerr("error: sum of bridges lengths is too big\n");
        exit(-1);
    }

    *name_islands = islands;
    *size = num_of_islands;
    mx_strdel(&file);
    return bridges;
}

