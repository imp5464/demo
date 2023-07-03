#Name : Sahil Nawaz

def get_number_of_squares_adding_up_to_n(n):
    """ Input: n = 12
        Output: 3
        Explanation: 12 = 4 + 4 + 4.
    """

    if n <= 3:
        return n
 
   
    res = n
 
   
    for x in range(1, n + 1):
        temp = x * x
        if temp > n:
            break
        else:
            res = min(res, 1 + get_number_of_squares_adding_up_to_n(n
                                  - temp))
     
    return res
 
        

    
    
  
