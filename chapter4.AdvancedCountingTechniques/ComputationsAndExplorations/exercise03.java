/*
 * exercise03.java
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Find as many prime Fibonacci numbers as you can. It is
 * unknown whether there are inifinitely many of these
 */

import java.math.BigInteger;
import java.util.HashMap;
import java.util.Map;

class Fibonacci {
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
    private static boolean isPrime(BigInteger bi)
    {
        return bi.isProbablePrime(10000);
    }
}

public class exercise03
{
    public static void main(String... args)
    {
        for (int i = 1; i < Integer.MAX_VALUE; i++)
        {
            BigInteger bi = getFib(i);
            if (isPrime(bi))
            {
                System.out.println(bi);
            }
        }
    }
}
