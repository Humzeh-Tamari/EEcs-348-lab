/*
* EECS 348 Lab6
*IDE, compiled programs (C++ programming), Git
*Inputs: input Folder
*Outputs: results of adding multiplying and subtracting the input matrixes
*Collabs: Professor's notes, quick google
*Creator: Humzeh Emad Al-Tamari
*KUID: 3068260
*10/22/2023
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


// Function prototypes
int Msize(string fileName);
void readMatricesFromFile(string fileName, vector<vector<int>>& matrixA, vector<vector<int>>& matrixB);
void printMatrix(const vector<vector<int>>& matrix, const string& matrixName, int mSize);
void addMatrices(const vector<vector<int>>& matrixA, const vector<vector<int>>& matrixB, vector<vector<int>>& result, int mSize);
void multiplyMatrices(const vector<vector<int>>& matrixA, const vector<vector<int>>& matrixB, vector<vector<int>>& result, int mSize);
void subtractMatrices(const vector<vector<int>>& matrixA, const vector<vector<int>>& matrixB, vector<vector<int>>& result, int mSize);

int main() {
    //the N  in a NxN sized matrix
    const int mSize = Msize("sample_matrix.txt");

    vector<vector<int>> matrixA(mSize, vector<int>(mSize));//declaring matrix A
    vector<vector<int>> matrixB(mSize, vector<int>(mSize));//declaring matrix B

    readMatricesFromFile("sample_matrix.txt", matrixA, matrixB);//reads in matrixs A and B from the file then stores them in the variables we made

    vector<vector<int>> sumMatrix(mSize, vector<int>(mSize));//delare a matrix for summation
    vector<vector<int>> productMatrix(mSize, vector<int>(mSize));//declares a matrix for multiplication
    vector<vector<int>> diffMatrix(mSize, vector<int>(mSize));//declares a matrix for subtraction

    addMatrices(matrixA, matrixB, sumMatrix, mSize);// Add matrices A and B

    multiplyMatrices(matrixA, matrixB, productMatrix, mSize);// Multiply matrices A and B

    subtractMatrices(matrixA, matrixB, diffMatrix, mSize);// Subtract matrix B from matrix A

    // Display the results
    cout << "Humzeh Al-Tamari\nLab #6:IDE, compiled programs (C++ programming), Git\n\n";

    printMatrix(matrixA, "Matrix A", mSize);
    printMatrix(matrixB, "Matrix B", mSize);

    cout << "Matrix Sum (A + B):\n";
    printMatrix(sumMatrix, "  ", mSize);

    cout << "Matrix Product (A * B):\n";
    printMatrix(productMatrix, "  ", mSize);

    cout << "Matrix Difference (A - B):\n";
    printMatrix(diffMatrix, "  ", mSize);

    return 0;
}

/*
* Params:fielname
* Returns: mastrixSize
* this function gets the matrix size from the file then returns it to store for later use
*/
int Msize(string fileName) {
    //opends the file
    ifstream inputFile(fileName);
    if (inputFile.is_open()) {
        //initializes the variable
        int matrixSize;
        //grabs teh size
        inputFile >> matrixSize;

        inputFile.close();

        return matrixSize;
    }
    else {
        cerr << "Error: Unable to open the file " << fileName << endl;
    }
}

/*
* Params:fielname, matrixA, matrixB
* this function reads in and stores the matrixes into 2D vectores
*/
void readMatricesFromFile(string fileName, vector<vector<int>>& matrixA, vector<vector<int>>& matrixB) {
    //opens the file
    ifstream inputFile(fileName);
    if (inputFile.is_open()) {

        int mSize;
        inputFile >> mSize;

        // Read Matrix A
        for (int i = 0; i < mSize; i++) {
            for (int j = 0; j < mSize; j++) {
                inputFile >> matrixA[i][j];
            }
        }

        // Read Matrix B
        for (int i = 0; i < mSize; i++) {
            for (int j = 0; j < mSize; j++) {
                inputFile >> matrixB[i][j];
            }
        }

        inputFile.close();
    }
    else {
        cerr << "Error: Unable to open the file " << fileName << endl;
    }
}



/*
* Params:matrix,matrixName,mSize
* this function takes in a matrix, its name, and size then prints it out on display
*/
void printMatrix(const vector<vector<int>>& matrix, const string& matrixName, int mSize) {
    //prints out the name of the matrix we are showing
    cout << matrixName << ":\n";

    //prints out the matrix
    for (int i = 0; i < mSize; i++) {
        for (int j = 0; j < mSize; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/*
* Params:matrixA,matrixB,result,mSize
* this function takes in two matrixes adds them and stores it in the specified matrixs
*/
void addMatrices(const vector<vector<int>>& matrixA, const vector<vector<int>>& matrixB, vector<vector<int>>& result, int mSize) {
    //adds the matrixes
    for (int i = 0; i < mSize; i++) {
        for (int j = 0; j < mSize; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

/*
* Params:matrixA,matrixB,result,mSize
* this function takes in two matrixes multiplies them and stores it in the specified matrixs
*/
void multiplyMatrices(const vector<vector<int>>& matrixA, const vector<vector<int>>& matrixB, vector<vector<int>>& result, int mSize) {
    //multiplies the matrixes
    for (int i = 0; i < mSize; i++) {
        for (int j = 0; j < mSize; j++) {
            result[i][j] = 0;
            for (int k = 0; k < mSize; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

/*
* Params:matrixA,matrixB,result,mSize
* this function takes in two matrixes subtracts them and stores it in the specified matrixs
*/
void subtractMatrices(const vector<vector<int>>& matrixA, const vector<vector<int>>& matrixB, vector<vector<int>>& result, int mSize) {
    //subtracts the matrixes
    for (int i = 0; i < mSize; i++) {
        for (int j = 0; j < mSize; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}
