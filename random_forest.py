x = [4,8,12,16,1,4,9,16]
y = [1,4,9,16,4,8,12,3]
label = [0,0,1,1,0,1,1,1]

def calc_gini(arr):
    tot_sum = 0
    for a in arr:
        tot_sum = tot_sum + a
    
