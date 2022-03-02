#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//  (Task 1) Define a function called Date_Read which uses scanf to get the
//  data for a date. Fields are to be entered as three separate int values
//  in the format "%d/%d/%d". Dates will be entered with day first, followed by
//  month, followed by year.
//
//  Parameters:
//      d - the address of an integer which will represent the day.
//      m - the address of an integer which will represent the month.
//      y - the address of an integer which will represent the year.
//
//  Returns:
//      The function must return a boolean value indicating the status of the
//      I/O operation. The result is true if and only if three integer values
//      have been successfully parsed using the designated format string.
//
//      Do not try to perform other data validation in this function.

double Date_Read(int *d, int *m, int *y)
{
  int result = scanf("%d/%d/%d", d, m, y);

  if (result == 3)
  {
    return true;
  }
  else
  {
    return false;
  }
}

//  (Task 2) Define a function called Date_Write which uses printf to
//  display the value of a date in format "%d/%d/%d", with day followed by month
//  followed by year.
//
//  Parameters:
//      d - an integer which will represent the day.
//      m - an integer which will represent the month.
//      y - an integer which will represent the year.
//
//  Returns:
//      Nothing.

double Date_Write(int d, int m, int y)
{
  printf("%d/%d/%d", d, m, y);
  return true;
}

//  (Task 3) Define a function called Date_Compare which compares two
//  dates. Your implementation may assume that these values are valid dates.
//
//  Parameters:
//      d1, m1, y1 - Three integers representing the first date.
//      d2, m2, y2 - Three integers representing the second date.
//
//  Returns:
//      An int which is:
//      -1  if the date represented by (d1, m1, y1) is before that
//          represented by (d2, m2, y2);
//      0   if the two values represent the same date;
//      +1  otherwise.

double Date_Compare(int d1, int m1, int y1, int d2, int m2, int y2)
{
  if (y2 > y1)
  {
    return -1;
  }

  else if ((y1 == y2) && (m2 > m1))
  {
    return -1;
  }

  else if ((y1 == y2) && (m1 == m2) && (d2 > d1))
  {
    return -1;
  }

  else if ((y1 == y2) && (m1 == m2) && (d1 == d2))
  {
    return 0;
  }

  else
  {
    return 1;
  }
}

//  (Task 4) Implement the Date_Valid function which determines if the
//  supplied date is valid:
//  *   Year must be greater than or equal to 1.
//  *   Month must between 1 and 12 inclusive.
//  *   Day must be at least 1, with upper limits given below:
//      30 days: September, April June, and November.
//      31 days: January, March, May, July, August, October, December.
//      28 or 29: February (usually 28, but 29 in a leap year).
//
//  A year is a leap year if it is divisible by 400, or if it is
//  divisible by 4 but not divisible by 100.
//
//  Parameters:
//     d, m, y - three integers representing a date.
//
//  Returns:
//      Returns true if and only if the supplied date is valid according to
//      the definition listed above.
double leap_year(int y)
{
  if (y % 400 == 0)
  {
    return true;
  }
  else if ((y % 4 == 0) && (y % 100 != 0))
  {
    return true;
  }
  else
  {
    return false;
  }
}

double dmy(int d, int m, int y)
{
  if (y > 0)
  {
    if (d > 0 && d < 31)
    {
      if ((m > 0 && m < 13) && (m != 2))
      {
        return true;
      }
      else
      {
        return false;
      }
    }
    else
    {
      return false;
    }
  }
  else if (d == 31)
  {
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }
}

double check_feb(int d, int m, int y)
{
  if (d <= 28 && m == 2)
  {
    return true;
  }
  else if (d == 29 && m == 2)
  {
    if (leap_year(y) == true)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }
}
double Date_Valid(int d, int m, int y)
{
  if ((dmy(d, m, y) == true) || (check_feb(d, m, y)) == true)
  {
    return true;
  }
  else
  {
    return false;
  }
}

//  (Task 5) Define a function called Date_Match which compares a query date to
//  a list of dates. The function returns the position of the first object in
//  the list which satisfies a designated criterion.
//
//  If criterion is -1, then the function returns the position of
//  the first date in the list that comes before the query date. If criterion is
//  +1, then the function returns the position of the first date in the list
//  that comes after the query date. If criterion is 0, then the function returns
//  the position of the first date in the list that is equal to the query.
//
//  Parameters:
//      d, m, y    - Three integers which represents a query date.
//
//      dd, mm, yy - Three integer arrays, holding respective days, months and
//                   years of a list of dates.
//
//      num_dates  - an int which tells the function how many elements there
//                   are in the array.
//
//      criterion  - an int (guaranteed to be -1, 0, or 1) which defines the
//                   matching criterion.
//
//  Returns:
//      The integer position of the first item in the list which satisfies the
//      matching criterion.
//
//      If num_dates is equal to or less than 0, the function returns -1.
//
//      If the query is not a valid date, the function returns -1.
//
//      If there is integer i for which
//          0 <= i < num_dates,
//      and
//          Date_Valid( dd[i], mm[i], yy[i] )
//      and
//          Date_Compare( dd[i], mm[i], yy[i], d, m, y ) == criterion
//      then
//          the function returns i.
//
//      Otherwise the function returns -1.

double Date_Match(int d, int m, int y, int dd[], int mm[], int yy[], int num_dates, int criterion)
{
  if (num_dates > 0)
  {
    for (int i = 0; i < num_dates; i++) //check the entire list of dates;
    {
      if (Date_Valid(dd[i], mm[i], yy[i]) == true) //if the date is valid...
      {
        int comparison = Date_Compare(dd[i], mm[i], yy[i], d, m, y);
        if (comparison == criterion) // if the compared the date matches the criterion of -1...
        {
          return i+1; // return the current position.
        }
        else
        {
          continue;
        }
      }
      else
      {
        continue;
      }
    }

  }

  else if (num_dates < 1) //if no dates exist, exit the program.
  {
    return -1;
  }

  else if (Date_Valid(d, m, y) == false) //if no VALID dates exist, exit the program.
  {
    return -1;
  }

  return -1;
}

//----------------------------------------------------------------------------

// the code below this line is provided so you can test your program on your PC.
// THIS AMS QUESTION REQUIRES THAT YOU REMOVE THE MAIN FUNCTION WHEN YOU SUBMIT.

//Do NOT remove main when testing on your PC.
//Only remove it for submission.

//------------------------------------------------------------------------------
