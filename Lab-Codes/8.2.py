def lcs(X, Y):
    m = len(X)
    b = len(Y)
    
    # Creating the LCS table
    L = [[0] * (b + 1) for _ in range(m + 1)]
    
    # Building the LCS table in bottom-up fashion
    for i in range(m + 1):
        for j in range(b + 1):
            if i == 0 or j == 0:
                L[i][j] = 0
            elif X[i - 1] == Y[j - 1]:
                L[i][j] = L[i - 1][j - 1] + 1
            else:
                L[i][j] = max(L[i - 1][j], L[i][j - 1])
    
    # Length of LCS is in L[m][b]
    length_of_lcs = L[m][b]
    
    # Reconstructing the LCS from the table
    index = length_of_lcs
    lcs = [''] * (index + 1)
    lcs[index] = ''  # Set the terminating empty character
    
    # Start from the bottom right corner and one by one store characters in lcs[]
    i = m
    j = b
    while i > 0 and j > 0:
        if X[i - 1] == Y[j - 1]:
            lcs[index - 1] = X[i - 1]
            i -= 1
            j -= 1
            index -= 1
        elif L[i - 1][j] > L[i][j - 1]:
            i -= 1
        else:
            j -= 1
    
    return ''.join(lcs), length_of_lcs

# Input
X = input("Enter the first string into an array: ")
Y = input("Enter the second string into an array: ")

# Find LCS
lcs_str, lcs_len = lcs(X, Y)

# Output
print(f"LCS: {lcs_str}")
print(f"LCS Length: {lcs_len}")
