/*
 * exercise01.java
 * Copyright (C) 2017 zrlx <zrlx@MyFreeBSD>
 *
 * Distributed under terms of the MIT license.
 *
 * Find the exact value of f100, f500, and f1000, where fn is
 * the nth Fibonacci number
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
}

public class exercise01
{
    public static void main(String... args)
    {
        System.out.println(Fibonacci.getFib(100));
        System.out.println(Fibonacci.getFib(500));
        System.out.println(Fibonacci.getFib(1000));
    }
}
