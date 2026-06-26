#!/usr/bin/python3
"""Module that provides a function to calculate minimum operations."""


def minOperations(n):
    """Calculate the minimum number of operations to obtain exactly n H.

    Args:
        n (int): The target number of characters.

    Returns:
        int: The minimum number of operations, or 0 if n is impossible
            to achieve.
    """
    if n <= 1:
        return 0

    operations = 0
    factor = 2

    while n > 1:
        while n % factor == 0:
            operations += factor
            n //= factor
        factor += 1

    return operations
