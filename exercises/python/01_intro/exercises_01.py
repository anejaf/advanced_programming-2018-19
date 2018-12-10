
def is_palindrome(string_var):     
    '''
    returns True if string_var is palindrome, False otherwise
    '''
    for i in range(int(len(string_var) / 2)):
        if string_var[i] != string_var[-1-i]:
            return False
    return True

def histogram_letters(string_var):     
    '''
    count how many times a letter is present in the string_var
    and returns a dict

    '''
    hist = {}
    for letter in string_var:
        if letter in hist.keys():
            hist[letter] += 1
        else:
            hist[letter] = 1
    return hist

def get_most_frequent(list_var):
    '''
    returns a tuple with the most frequent object in the list with the 
    corresponing number
    as it is now, it returns only one of the max elements if there are multiple
    '''
    return max(histogram_letters(list_var).items(), key=lambda k: k[1])

def which_duplicates(list_var):
    '''
    return a dict with containing the repeted object and the number of repetitions
    '''
    return dict([el for el in histogram_letters(list_var).items() if el[1] > 1])


def compute_factorial(int_val):
    '''
    returns factorial of a number
    '''
    ret = 1
    for i in range(1, int_val+1):
        ret *= i
    return ret


def is_prime(int_val):
    '''
    returns True if int_val is prime, False otherwise
    '''
    if int_val < 4:
        return int_val > 1
    if int_val % 2 == 0 or int_val % 3 == 0:
        return False
    i = 5
    while i*i <= int_val:
        if int_val % i == 0 or int_val % (i+2) == 0:
            return False
        i += 1
    return True

        

