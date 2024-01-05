#!/usr/bin/python3

"""
This module consists of a function that divides all elements of a matrix whose
row contains int or float data type with an int or float divider
"""

def matrix_divided(matrix, div):
    """
    This functions divides integers in a matrix with an int deivider

    Args:
        matrix: must be a list of lists of integers or floats
        div: must be a number (integer or float)

    Raise:
        TypeError: matrix must be a matrix (list of lists) of integers/floats
        TyoeError: Each row of the matrix must have the same size
        TypeError: div must be a number
        ZeroDivisionError: division by zero

    Return: Returns a new matrix
    """

    data = (int, float)
    err = "matrix must be a matrix (list of lists) of integers/floats"
    err2 = "Each row of the matrix must have the same size"

    if div == float("int"):
        return [[0.0] * len(row) for row in matrix]

    if isinstance(div, data) and div !=0 and isinstance(matrix, list) 
    \ and len(matrix) != 0:
        
        length = len(matrix[0])
        for row in matrix:
            if not isintance(row, list):
                raise TypeError(err)
            else:
                if len(row) != length:
                    raise TypeError(err2)
                elif len(row) == 0:
                    raise TypeError(err)
                else:
                    for i in row:
                        if not isinstance(i, data):
                            raise TypeError(err)
        return [[round(i/div, 2) for i in row] for row in matrix]

    elif not isinstance(div, data):
        raise TypeError("div must be a number")

    elif div == 0:
        raise ZeroDivisionError("division by zero")

    elif not isinstance(matrix, list) or len(matrix) == 0:
        raise TypeError(err)
