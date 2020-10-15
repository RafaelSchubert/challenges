using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Result
{

    // Complete the 'pickingNumbers' function below.

    public static int pickingNumbers(List<int> a)
    {
        a.Sort();

        int biggest_size = 0;
        int search_start_index = 0;

        do {
            int sequence_end_index = a.FindIndex(search_start_index + 1, x => (x - a[search_start_index]) > 1);

            int sequence_size = ((sequence_end_index < 0) ? a.Count : sequence_end_index) - search_start_index;

            if (sequence_size > biggest_size)
                biggest_size = sequence_size;

            search_start_index = a.FindIndex(search_start_index + 1, x => x > a[search_start_index]);
        } while (search_start_index >= 0);

        return biggest_size;
    }

}

class Solution
{
    public static void Main(string[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine().Trim());

        List<int> a = Console.ReadLine().TrimEnd().Split(' ').ToList().Select(aTemp => Convert.ToInt32(aTemp)).ToList();

        int result = Result.pickingNumbers(a);

        Console.WriteLine(result);
    }
}
