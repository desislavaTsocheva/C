#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Points{
    double x;
    double y;
    double z;
};

double distance(struct Points p1,struct Points p2)
{
        return sqrt(pow(p2.x-p1.x,2)+pow(p2.y-p1.y,2)+pow(p2.z-p1.z,2));
}

int isCollinear(struct Points p1, struct Points p2, struct Points p3) {
    double ax = p2.x - p1.x, ay = p2.y - p1.y, az = p2.z - p1.z;
    double bx = p3.x - p1.x, by = p3.y - p1.y, bz = p3.z - p1.z;
    double cx = ay * bz - az * by;
    double cy = az * bx - ax * bz;
    double cz = ax * by - ay * bx;
    return (cx == 0 && cy == 0 && cz == 0);
}

void Triangle(struct Points *arr,int length)
{
    if(length<3)
    {
        printf("Not enough points to form a triangle");
        return;
    }

    double ab=distance(arr[0],arr[1]);
    double ac=distance(arr[0],arr[2]);
    double bc=distance(arr[1],arr[2]);
    printf("AB= %.2lf\n",ab);
    printf("AC= %.2lf\n",ac);
    printf("BC= %.2lf\n",bc);

    if(ab+ac<bc||ac+bc<ab||ab+bc<ac){
        printf("Can't form a triangle \n");
    }

    if(isCollinear(arr[0],arr[1],arr[2])){
        printf("Pointers are collinear, cannot form a triangle!!! \n");
    }
}

int main()
{
    struct Points *arr;

    int length;
    printf("Enter arr length: ");
    scanf("%d",&length);

    double x,y,z;

    printf("\n");

    arr=(struct Points*)malloc(length*sizeof(struct Points));

    for(int i=0;i<length;i++){
        printf("Enter coordinate x: ");
        scanf("%lf",&x);
        arr[i].x=x;
        printf("Enter coordinate y: ");
        scanf("%lf",&y);
        arr[i].y=y;
        printf("Enter coordinate z: ");
        scanf("%lf",&z);
        arr[i].z=z;
    }
    for(int i=0;i<length;i++){
        printf("%lf - %lf - %lf \n",arr[i].x,arr[i].y,arr[i].z );
    }

    Triangle(arr,length);
    free(arr);
    return 0;

}
