int numberOfChild(int n, int k) {
    int round_length = n - 1;
    int rounds = k / round_length;
    int rem = k % round_length;
    if (rounds % 2 == 0) {
        return rem;
    } 
    else {
        return (n - 1) - rem;
    }
}
