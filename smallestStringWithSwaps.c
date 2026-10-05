
int findRoot(int* parent, int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = findRoot(parent, parent[i]);
}

void unionSets(int* parent, int i, int j) {
    int rootI = findRoot(parent, i);
    int rootJ = findRoot(parent, j);
    if (rootI != rootJ) {
        parent[rootI] = rootJ;
    }
}

char* smallestStringWithSwaps(char* s, int** pairs, int pairsSize, int* pairsColSize) {
    int n = strlen(s);
    if (n == 0) return s;
    int* parent = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < pairsSize; i++) {
        unionSets(parent, pairs[i][0], pairs[i][1]);
    }
    int** counts = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        counts[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        int root = findRoot(parent, i);
        if (counts[root] == NULL) {
            counts[root] = (int*)calloc(26, sizeof(int));
        }
        counts[root][s[i] - 'a']++;
    }

    // Reconstruct the result string using the sorted counts bucket by bucket
    for (int i = 0; i < n; i++) {
        int root = findRoot(parent, i);
        for (int c = 0; c < 26; c++) {
            if (counts[root][c] > 0) {
                s[i] = 'a' + c;
                counts[root][c]--;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (counts[i] != NULL) {
            free(counts[i]);
        }
    }
    free(counts);
    free(parent);

    return s;
}
