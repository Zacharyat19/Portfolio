import sys
INT_MIN = -32767

def parse_input(file_name):
    f = open(file_name, "r")
    vals = [int(val) for val in f.readline().strip().split()]
    f.close()
    return vals
    
def maximum_total_retail_value(vals):
    n = len(vals)
    table = [0 for x in range(n + 1)]
 
    for i in range(1, n + 1):
        max_val = INT_MIN
        for j in range(i):
             max_val = max(max_val, vals[j] + table[i - j - 1])
        table[i] = max_val
 
    return table[n]
    
log_vals = parse_input(sys.argv[1])
print(maximum_total_retail_value(log_vals))