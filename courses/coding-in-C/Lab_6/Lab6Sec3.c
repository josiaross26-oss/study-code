/*
 * File: main.c
 * Description: Auswertung zweier Sensoren
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    float time; 
    double probability;
} sensor_data;


typedef struct
{
    int id;
    double threshold;
    sensor_data data[3000];
    int object_detection[3000];
} sensor;

/**
 * @brief Ließt die Werte eines Sensors ein
 * @param[in]  Pointer auf einen Sensor
 * @param[in]  Pointer auf den Namen der FILE-Datei
 * @return            void
 */
void einlesen(sensor *sensor, char *name_sensor)
{
    FILE *lesen1 = fopen(name_sensor, "r");
    if (lesen1 == NULL)
    {
        printf("Fehler");
        exit(0);
    }

    for (int i=0; i<3000; i++)
    {
        if (fscanf(lesen1, "%f %lf", &sensor->data[i].time, &sensor->data[i].probability) != 2)
        {
            printf("Fehler");

            if (fclose(lesen1) != 0)
            {
                printf("Fehler");
            }
            exit(0);
        } 
    }

    if (fclose(lesen1) != 0)
    {
        printf("Fehler");
    }
}

void detection(sensor *sensor)
{
    for (int i=0; i<3000; i++)
    {
        if (sensor->data[i].probability >= sensor->threshold)
        {
            sensor->object_detection[i] = 1;
        }

        else 
        {
            sensor->object_detection[i] = 0;
        }
    }
}

void detection_time(sensor *sensor, int id)
{
    float start_zeit = 0;
    float end_zeit = 0;

    printf("Sensor %d detections:\n", id);

    for (int i=1; i<3000; i++)
    {
        if (sensor->object_detection[i-1] < sensor->object_detection[i])
        {
            start_zeit = sensor->data[i].time;
        }

        else if (sensor->object_detection[i-1] > sensor->object_detection[i])
        {
            end_zeit = sensor->data[i-1].time;
            printf("Start: %.2f s     End: %.2f s\n", start_zeit, end_zeit);
        }
    }

    if (sensor->object_detection[2999] == 1)
    {
        end_zeit = sensor->data[2999].time;
        printf("Start: %.2f s     End: %.2f s\n", start_zeit, end_zeit);
    }
    printf("\n\n");
}

void detection_combined(sensor *sensor1, sensor *sensor2)
{
    float start_zeit = 0;
    float end_zeit = 0;

    printf("Fused signal (both sensors):\n");

    for (int i=1; i<3000; i++)
    {
        if (sensor1->object_detection[i] == 1 && sensor2->object_detection[i] == 1)
        {
            if (sensor1->object_detection[i-1] == 0 || sensor2->object_detection[i-1] == 0)
            {
                start_zeit = sensor1->data[i].time;
            }
        }

        else if (sensor1->object_detection[i] == 0 || sensor2->object_detection[i] == 0)
        {
            if (sensor1->object_detection[i-1] == 1 && sensor2->object_detection[i-1] == 1)
            {
                end_zeit = sensor1->data[i-1].time;
                printf("Start: %.2f s     End: %.2f s\n", start_zeit, end_zeit);
            }
        }
    }

    if (sensor1->object_detection[2999] == 1 && sensor2->object_detection[2999] == 1)
    {
        end_zeit = sensor1->data[2999].time;
        printf("Start: %.2f s     End: %.2f s\n", start_zeit, end_zeit);
    }
}

int main()
{
    sensor sensor1;
    sensor1.id = 1;
    sensor1.threshold = 0.8;
    char name_sensor1[] = "sensor1.txt";
    einlesen(&sensor1, name_sensor1);

    detection(&sensor1);
    detection_time(&sensor1, sensor1.id);

    sensor sensor2; 
    sensor2.id = 2;
    sensor2.threshold = 0.7;
    char name_sensor2[] = "sensor2.txt";
    einlesen(&sensor2, name_sensor2);

    detection(&sensor2);
    detection_time(&sensor2, sensor2.id);

    detection_combined(&sensor1, &sensor2);

    return 0;
}