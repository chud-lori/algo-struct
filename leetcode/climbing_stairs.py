def climbsta(n: int):
    """
    using tabulation
    """
    # First approach, native
    if n == 1:
        return 1

    # initailize table / base cases
    dp = [0] * (n + 1)
    dp[0] = 1
    dp[1] = 1

    for i in range(2, n+1):
        dp[i] = dp[i-1] + dp[i-2]

    return dp[n]

def climbstasp(n: int):
    "for better space complexity"

    a, b = 1, 1

    for i in range(2, n+1):
        a, b = b, a+b

    return b


"""
dp[0] = 1
dp[1] = 1

Loop 1:
dp[1] (1) + dp[0] (1)
dp[2] = 2

Loop 2
dp[2] (2) + dp[1] (1)
dp[3] = 3

"""


n = 2

assert climbstasp(2) == 2

n = 3

assert climbstasp(3) == 3
