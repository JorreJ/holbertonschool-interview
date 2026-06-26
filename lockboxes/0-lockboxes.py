#!/usr/bin/python3
"""Determines if all the boxes can be opened."""


def canUnlockAll(boxes):
    """
    Return True if all boxes can be opened, otherwise False.

    Args:
        boxes (list): List of lists containing keys.

    Returns:
        bool
    """
    n = len(boxes)

    # Ensemble des boîtes déjà ouvertes
    opened = set([0])

    # Pile pour explorer les nouvelles boîtes
    stack = [0]

    while stack:
        current = stack.pop()

        for key in boxes[current]:
            if 0 <= key < n and key not in opened:
                opened.add(key)
                stack.append(key)

    return len(opened) == n
