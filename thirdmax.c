int thirdMax(int* nums, int numsSize) {
    long long m1 = 0, m2 = 0, m3 = 0;
    bool has_m1 = false, has_m2 = false, has_m3 = false;
    for (int i = 0; i < numsSize; i++) {
        long long val = nums[i];
        if ((has_m1 && m1 == val) || (has_m2 && m2 == val) || (has_m3 && m3 == val)) {
            continue;
        }
        if (!has_m1 || val > m1) {
            m3 = m2;
            has_m3 = has_m2;
            m2 = m1;
            has_m2 = has_m1;
            m1 = val;
            has_m1 = true;
        } else if (!has_m2 || val > m2) {
            m3 = m2;
            has_m3 = has_m2;
            m2 = val;
            has_m2 = true;
        } else if (!has_m3 || val > m3) {
            m3 = val;
            has_m3 = true;
        }
    }
    return has_m3 ? (int)m3 : (int)m1;
}