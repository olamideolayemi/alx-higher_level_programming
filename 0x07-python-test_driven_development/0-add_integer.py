#!/bin/usr/python3
"""
This modules consist of a function that adds two (2) integers. Any other data type is considered invalid.
"""

def add_integer(a, b=98):
    """
    Returns the sum of two integers of data type int or float as one.

    Args:
        a: First number
        b: Second Number

    Return: a + b
    """

    data = (int, float)

    if not isinstance(a, data):
        raise TypeError("a must be an integer")
    elif not isinstance(b, data):
        raise TypeError("b must be an integer")
    else:
        return int(a) + int(b)
