// you will have to modity the path when you download it, for some reason my computer dosnt liek reltive paths 

//#include <C:\Users\caleb\Desktop\361\361-HART-Sensor\main\cJSON\cJSON.h>
#include <\Users\Joseph Malcarne\Desktop\361\361-HART-Sensor\main\cJSON\cJSON.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int error;

} config;

void to_struct(cJSON *root){
    // Loop through all items in the root JSON
    cJSON *item = NULL;
    cJSON_ArrayForEach(item, root) {
        if (cJSON_IsNumber(item)) {
            printf("%s: %d\n", item->string, item->valueint);
        } else if (cJSON_IsString(item)) {
            printf("%s: %s\n", item->string, item->valuestring);
        } else if (cJSON_IsArray(item)) {
            printf("%s:\n", item->string);
            cJSON *arrayItem;
            cJSON_ArrayForEach(arrayItem, item) {
                if (cJSON_IsString(arrayItem)) {
                    printf("  - %s\n", arrayItem->valuestring);
                }
            }
        }
    }
}


int main(void) {
    FILE *fp = fopen("config.cfg", "r");
    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *cfg_string = (char *)malloc(fsize + 1);
    fread(cfg_string, 1, fsize, fp);
    cfg_string[fsize] = '\0';
    fclose(fp);

    // Parse the JSON string
    cJSON *root = cJSON_Parse(cfg_string);
    free(cfg_string);

    if (root == NULL) {
        // Handle parsing error
        return -1;
    }

    to_struct(root);


    // Don't forget to clean up
    cJSON_Delete(root);
    return 0;
}