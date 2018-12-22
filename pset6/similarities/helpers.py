from enum import Enum
import copy

class Operation(Enum):
    """Operations"""

    DELETED = 1
    INSERTED = 2
    SUBSTITUTED = 3

    def __str__(self):
        return str(self.name.lower())


def distances(a, b):
    """Calculate edit distance from a to b"""

    # TODO
    if len(a) == 1 and len(b) == 1:
        if a[0] == b[0]:
            return [[(0,None), (1, Operation.INSERTED)], [(1, Operation.DELETED), (0, Operation.SUBSTITUTED)]]
        else:
            return [[(0,None), (1, Operation.INSERTED)], [(1, Operation.DELETED), (1, Operation.SUBSTITUTED)]]
    elif len(a) == 0 and len(b) == 0:
        return [[(0,None)]]
    elif len(a) == 0:
        tmp = [[(0,None)]]
        for i in range(0, len(b)):
            tmp[0].append((i + 1,Operation.INSERTED))

        return tmp
    elif len(b) == 0:
        tmp = [[(0,None)]]
        for i in range(0, len(a)):
            tmp.append([(i + 1,Operation.DELETED)])
        #print(tmp)
        return tmp
    #setting up general case

    matrix1 = copy.copy(distances(a[ : -1], b))
    matrix2 = copy.copy(distances(a, b[ : -1])[len(a)])
    matrix2.append([])
    matrix = matrix1 + [matrix2]

    #calculate the value of matrix[len(a)][len(b)]
    i = len(a)
    j = len(b)
    cost_del = matrix[i - 1][j][0] + 1
    cost_ins = matrix[i][j - 1][0] + 1
    if a[i - 1] == b[j - 1]:
        cost_sub = matrix[i - 1][j - 1][0]
    else:
        cost_sub = matrix[i - 1][j - 1][0] + 1

    min_cost = min(cost_del, cost_ins, cost_sub)
    if min_cost == cost_del:
        min_operation = Operation.DELETED
    elif min_cost == cost_ins:
        min_operation = Operation.INSERTED
    else:
        min_operation = Operation.SUBSTITUTED

    matrix[i][j] = (min_cost, min_operation)
    return matrix
