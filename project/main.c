#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// fill the ellipse
double ellipse(int slices, int lines, int colunms, int x, int y, int z) {
    // ellipse function (((int - centro) / raio)**2)
    double dalex = pow(((x - ((double) (slices  - 1) / 2)) / ((double) (slices  - 1) / 2)), 2);
    double daley = pow(((y - ((double) (lines   - 1) / 2)) / ((double) (lines   - 1) / 2)), 2);
    double dalez = pow(((z - ((double) (colunms - 1) / 2)) / ((double) (colunms - 1) / 2)), 2);

    // sum of the result of the function parameters (x + y + z = 1)
    if (dalex + daley + dalez <= 1) return 1;
    else return 0;
}

int main() {
    // variables
    int ***m;
    int slices, lines, colunms, slice;

    // input variables
    printf("Input of the number of slices: \n");
    scanf("%d", &slices);
    printf("Input ellipsis height: \n");
    scanf("%d", &lines);
    printf("Input ellipsis width: \n");
    scanf("%d", &colunms);
    printf("Input position (between 0 and %d) of the slice to be analyzed: \n", slices - 1);
    scanf("%d", &slice);

    // memory alocation
    m       = (int***) malloc(slices * sizeof(int**));
    m[0]    = (int**) malloc(slices * lines * sizeof(int*));
    m[0][0] = (int*) malloc(slices * lines * colunms * sizeof(int));

    // memory space of slices
    for(int i = 1; i < slices; i++) {
        m[i] = m[i - 1] + lines;
    }

    // memory space of lines
    for(int i = 0; i < slices; i++) {
        for(int j = 0; j < lines; j++) {
            if (i == 0 && j == 0);
            else m[i][j] = m[i][j - 1] + (colunms);
        }
    }

    // swapping the internal variables of the tridimensional array for the shape of the ellipse
    for(int i = 0; i < slices; i++) {
        for(int j = 0; j < lines; j++){
            for(int k = 0; k < colunms; k++){
                m[i][j][k] = ellipse(slices, lines, colunms, i, j, k);
            }
        }
    }

    // output of slice for analysis
    printf("Slice %d:\n", slice);
    for(int i = 0; i < lines; i++) {
        for(int j = 0; j < colunms; j++){
            printf("%d", m[slice][i][j]);
        }
        printf("\n");
    }

    // delete memory alocation
    free(m[0][0]);
    free(m[0]);
    free(m);

    return 0;
}
