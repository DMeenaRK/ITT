bool isBalanced(char* num) {
    int even_sum = 0;
    int odd_sum = 0;
    int i = 0;
while (num[i] != '\0') {
       int digit_value = num[i] - '0'; 
        if ((i & 1) == 0) {
            even_sum += digit_value;
        } else {
            odd_sum += digit_value;
        }
        i++;
    }

    return even_sum == odd_sum;
}