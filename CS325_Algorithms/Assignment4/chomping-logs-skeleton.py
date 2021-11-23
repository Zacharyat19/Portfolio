import sys

def parse_input(file_name):
    f = open(file_name, "r")
    vals = [int(val) for val in f.readline().strip().split()]
    f.close()
    return vals
    
def maximum_total_retail_value(vals):
    # TODO: Implement this function!
    pass
    
log_vals = parse_input(sys.argv[1])
print(maximum_total_retail_value(log_vals))