#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cycle {
    char name[30];
    char model[30];
    int year;
    float price;
};

struct Car {
    int steeringWheelSize;
    struct Cycle cycle;
};

struct Motor {
    int rideSeatSize;
    struct Cycle cycle;
};

struct Boat {
    int deckSize;
    struct Cycle cycle;
};

struct Plane {
    int wingsLength;
    struct Cycle cycle;
};

void inputVehicle(struct Cycle *cycle, const char *type, void *vehicle) {
    printf("Enter %s details:\n", type);

    printf("Enter name: ");
    fgets(cycle->name, sizeof(cycle->name), stdin);
    cycle->name[strcspn(cycle->name, "\n")] = 0;

    printf("Enter model: ");
    fgets(cycle->model, sizeof(cycle->model), stdin);
    cycle->model[strcspn(cycle->model, "\n")] = 0;

    printf("Enter price: ");
    scanf("%f", &cycle->price);

    printf("Enter year: ");
    scanf("%d", &cycle->year);

    getchar();

    if (strcmp(type, "car") == 0) {
        printf("Enter steering wheel size: ");
        scanf("%d", &((struct Car *)vehicle)->steeringWheelSize);
    }
    else if (strcmp(type, "motor") == 0) {
        printf("Enter ride seat size: ");
        scanf("%d", &((struct Motor *)vehicle)->rideSeatSize);
    }
    else if (strcmp(type, "boat") == 0) {
        printf("Enter deck size: ");
        scanf("%d", &((struct Boat *)vehicle)->deckSize);
    }
    else if (strcmp(type, "plane") == 0) {
        printf("Enter wings length: ");
        scanf("%d", &((struct Plane *)vehicle)->wingsLength);
    }

    getchar();
}

void printVehicle(struct Cycle *cycle, const char *type) {
    printf("\n%s Info:\n", type);
    printf("Name: %s\n", cycle->name);
    printf("Model: %s\n", cycle->model);
    printf("Year: %d\n", cycle->year);
    printf("Price: %.2f\n", cycle->price);
}

int main() {
    struct Car car;
    struct Motor motor;
    struct Boat boat;
    struct Plane plane;

    inputVehicle(&car.cycle, "car", &car);
    inputVehicle(&motor.cycle, "motor", &motor);
    inputVehicle(&boat.cycle, "boat", &boat);
    inputVehicle(&plane.cycle, "plane", &plane);

    printVehicle(&car.cycle, "Car");
    printf("Steering Wheel Size: %d\n", car.steeringWheelSize);

    printVehicle(&motor.cycle, "Motor");
    printf("Ride Seat Size: %d\n", motor.rideSeatSize);

    printVehicle(&boat.cycle, "Boat");
    printf("Deck Size: %d\n", boat.deckSize);

    printVehicle(&plane.cycle, "Plane");
    printf("Wings Length: %d\n", plane.wingsLength);

    return 0;
}
