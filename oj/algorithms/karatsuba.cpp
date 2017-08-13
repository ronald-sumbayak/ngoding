def karatsuba (x,y):
    if len (str (x)) == 1 or len(str (y)) == 1:
        return x * y
    else:
        n = max (len (str (x)), len (str (y)))
        m = n / 2
        
        a = x / (10 ** m)
        b = x % (10 ** m)
        c = y / (10 ** m)
        d = y % (10 ** m)
        
        p0 = karatsuba (a, c)
        p1 = karatsuba (a+b, c+d) - p0 - p2
        p2 = karatsuba (b, d)
        
        result = (p0 * (10**(2*m))) + (p1 * 10**m) + p2
        return result
