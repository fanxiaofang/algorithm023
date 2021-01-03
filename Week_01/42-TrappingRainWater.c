//42-接雨水
int trap(int* height, int heightSize){
    int * left = &height[0];
    int * right = &height[heightSize - 1];
    int * cl = left + 1;
    int * cr = right - 1;
    int ret = 0;

    while (cl <= right && cr >= left) {
        if (*left > *right) {
            if (*cr >= *right) {
                ret += *right * (right - cr - 1);
                right = cr;
            }
            else
                ret -= *cr;
            --cr;
        }
        else {
            if (*cl >= *left) {
                ret += *left * (cl - left - 1);
                left = cl;
            }
            else
                ret -= *cl;
            ++cl;
        }
    }
    return ret;
}