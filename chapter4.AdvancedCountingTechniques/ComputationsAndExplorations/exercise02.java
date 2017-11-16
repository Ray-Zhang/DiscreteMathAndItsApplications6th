/*
 * exercise02.java
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Find the smallest Fibonacci number greater than
 * 1,000,000, greater than 1,000,000,000, and greater than
 * 1,000,000,000,000
 */

import java.math.BigInteger;
import java.util.HashMap;
import java.util.Map;

public class Fibonacci {
    private static Map<Integer, BigInteger> fibMap = new HashMap<Integer, BigInteger>();
    private static BigInteger getFib(int index)
    {
        if (index == 0 || index == 1)
            return BigInteger.ONE;
        if (fibMap.containsKey(index))
        {
            return fibMap.get(index);
        }
        else
        {
            BigInteger result = getFib(index-1).add(getFib(index-2));
            fibMap.put(index, result);
            return result;
        }
    }

    public static BigInteger smallestFibGreaterThan(BigInteger bi)
    {
        for (int i = 1;;i++)
        {

            if (bi.compareTo(getFib(i)) > 0)
                continue;
            else
                return getFib(i);
        }
    }
}

public class exercise02
{
    public static void main(String... args)
    {
        System.out.println(Fibonacci.smallestFibGreaterThan(new BigInteger("1000000")));
        System.out.println(Fibonacci.smallestFibGreaterThan(new BigInteger("1000000000")));
        System.out.println(Fibonacci.smallestFibGreaterThan(new BigInteger("1000000000000")));
    }
}

