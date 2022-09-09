/* Handwritten C codes for benchmarks */

#include "benchmarks.h"

#if defined(NOOPT)
  #pragma GCC push_options
  #pragma GCC optimize ("O0")
#endif

/*
  let sum : int array code -> int code = 
    C.to_code1 @@ fun arr ->
    of_arr arr
    |> fold C.(+) (C.int 0)
*/
int64_t sum(const int64_t arr[], const int64_t n)
{
  int64_t sum = 0;
  int i;
  for(i=0; i<n; i++)
    sum += arr[i];
  return sum;
}

/*
  let sumOfSquares : int array code -> int code =
    C.to_code1 @@ fun arr ->
    of_arr arr
    |> map C.(fun x -> x * x)
    |> fold C.(+) C.(int 0)
*/
int64_t sum_squares(const int64_t arr[], const int64_t n)
{
  int64_t sum = 0;
  int i;
  for(i=0; i<n; i++){
    const int64_t x = arr[i];
    sum += x * x;
  }
  return sum;
}

/*
  let sumOfSquaresEven : int array code -> int code
  = C.to_code1 @@ fun arr ->
    of_arr arr
    |> filter C.(fun x -> x mod (int 2) = int 0)
    |> map C.(fun x -> x * x)
    |> fold C.(+) C.(int 0)
*/
int64_t sum_squares_even(const int64_t arr1[], const int64_t size_arr1) {
  int64_t sum = 0;
  int i;
  for(i=0; i<size_arr1; ++i) {
    const int64_t t = arr1[i];
    if(t % 2 == 0) {
      sum += t * t;
    }
  }
  return sum;
}

/*
  let maps : int array code -> int code
    = C.to_code1 @@ fun arr ->
      of_arr arr
      |> map C.(fun x -> x * int 1)
      |> map C.(fun x -> x * int 2)
      |> map C.(fun x -> x * int 3)
      |> map C.(fun x -> x * int 4)
      |> map C.(fun x -> x * int 5)
      |> map C.(fun x -> x * int 6)
      |> map C.(fun x -> x * int 7)
      |> fold C.(+) C.(int 0)
*/
int64_t maps(const int64_t arr1[], const int64_t size_arr1) {
  int64_t sum = 0;
  int i;
  for(i=0; i<size_arr1; ++i) {
    sum += arr1[i] * 1 * 2 * 3 * 4 * 5 * 6 * 7;
  }
  return sum;
}

/*
  let filters : int array code -> int code
  = C.to_code1 @@ fun arr ->
    of_arr arr
    |> filter C.(fun x -> x > int 1)
    |> filter C.(fun x -> x > int 2)
    |> filter C.(fun x -> x > int 3)
    |> filter C.(fun x -> x > int 4)
    |> filter C.(fun x -> x > int 5)
    |> filter C.(fun x -> x > int 6)
    |> filter C.(fun x -> x > int 7)
    |> fold C.(+) C.(int 0)
*/
int64_t filters(const int64_t arr1[], const int64_t size_arr1) {
  int64_t sum = 0;
  int i;
  for(i=0; i<size_arr1; ++i) {
    const int64_t t = arr1[i];
    if(t>7) {
      sum += t;
    }
  }
  return sum;
}

/*
  let cart : (int array code * int array code) -> int code
  = C.to_code2 @@ fun (arr1, arr2) ->
      of_arr arr1
      |> flat_map (fun x -> of_arr arr2 |> map C.(fun y -> x * y))
      |> fold C.(+) C.(int 0)
*/
int64_t cart(const int64_t arr1[], const int64_t size_arr1, const int64_t arr2[], const int64_t size_arr2) {
  int64_t sum = 0;
  int i, j;
  for(i=0; i<size_arr1; ++i) {
    const int64_t t = arr1[i];
    for(j=0; j<size_arr2; ++j) {
      sum += t * arr2[j];
    } 
  }
  return sum;
}

/*
  let dotProduct : (int array code * int array code) -> int code
  = C.to_code2 @@ fun (arr1, arr2) ->
    zip_with C.( * ) (of_arr arr1) (of_arr arr2)
    |> fold C.(+) C.(int 0)
*/
int64_t dot_product(const int64_t arr1[], const int64_t size_arr1, const int64_t arr2[], const int64_t size_arr2) {
  int64_t sum = 0;
  int i;
  const int64_t size = (size_arr1 < size_arr2) ? size_arr1 : size_arr2;
  
  for(i=0; i<size; ++i) {
    sum += arr1[i] * arr2[i];
  }
  return sum;
}

/*
  let flatMap_after_zipWith : (int array code * int array code) -> int code
  = C.to_code2 @@ fun (arr1, arr2) ->
    zip_with C.( + ) (of_arr arr1) (of_arr arr1)
    |> flat_map (fun x -> of_arr arr2|> map C.(fun el -> el + x))
    |> fold C.(+) C.(int 0)
*/
int64_t flatmap_after_zipwith(const int64_t arr1[], const int64_t size_arr1, const int64_t arr2[], const int64_t size_arr2) {
  int64_t sum = 0;
  int i, j;
  for(i=0; i<size_arr1; ++i) {
    const int64_t t1 = arr1[i];
    const int64_t t2 = t1 + t1;
    for(j=0; j<size_arr2; ++j) {
      sum += arr2[j] + t2;
   }
  }
  return sum;
}

/*
  let zipWith_after_flatMap : (int array code * int array code) -> int code
  = C.to_code2 @@ fun (arr1, arr2) ->
    of_arr arr1
    |> flat_map (fun x -> of_arr arr2 |> map C.(fun y -> y + x))
    |> zip_with C.( + ) (of_arr arr1)
    |> fold C.(+) C.(int 0)
*/
int64_t zipwith_after_flatmap(const int64_t arr1[], const int64_t size_arr1, const int64_t arr2[], const int64_t size_arr2) {
  int64_t sum = 0;
  int i, j, i2;
  i2=0;
  for(i=0; i<size_arr1; ++i) {
    const int64_t t = arr1[i];
    for(j=0; j<size_arr2; ++j) {
      sum += (arr2[j] + t) + arr1[i2];
      i2++;
      if(i2 >= size_arr1) {
        return sum;
      }
    }
  }
  return sum;
}

/*
  let flat_map_take : (int array code * int array code) -> int code
  = C.to_code2 @@ fun (arr1, arr2) ->
        of_arr arr1
        |> flat_map (fun x -> of_arr arr2 |> map C.(fun y -> x * y))
        |> take (C.int 20_000_000)
        |> fold C.(+) C.(int 0)
*/
int64_t flat_map_take(const int64_t arr1[], const int64_t size_arr1, const int64_t arr2[], const int64_t size_arr2) {
  int64_t sum = 0;
  int i, j, c;
  c=0;
  for(i=0; i<size_arr1; ++i) {
    const int64_t t = arr1[i];
    for(j=0; j<size_arr2; ++j) {
      sum += t * arr2[j];
      c++;
      if(c>=20000000) {
        return sum;
      }
    }
  }
  return sum;
}

/*
  let zip_filter_filter :(int array code * int array code) -> int code
  = C.to_code2 @@ fun (arr1, arr2) ->
    zip_with C.( + )
      (of_arr arr1 |> filter C.(fun x -> x > int 7))
      (of_arr arr2 |> filter C.(fun x -> x > int 5))
    |> fold C.(+) C.(int 0)
*/
int64_t zip_filter_filter(const int64_t arr1[], const int64_t size_arr1, const int64_t arr2[], const int64_t size_arr2) {
  int64_t sum = 0;
  int i, j;
  i = 0;
  j = 0;
  while(i < size_arr1 && j < size_arr2) {
    while(!(arr1[i] > 7)) {
      ++i;
      if(i >= size_arr1) {
        return sum;
      } 
    }
    const int64_t t = arr2[j];
    if(t > 5) {
      sum += arr1[i] + t;
      ++i;
    }
    ++j;
  }
  return sum;
}

// int64_t zip_filter_filter2(const int64_t arr1[], const int64_t size_arr1, const int64_t arr2[], const int64_t size_arr2) {
//   int64_t sum = 0;
//   int i, j;
//   i = 0;
//   j = 0;
//   while(i < size_arr1 && j < size_arr2) {
//     while(!(arr1[i] > 7)) {
//       ++i;
//       if(i >= size_arr1) {
//         return sum;
//       } 
//     }
//     while(!(arr2[j] > 5)) {
//       ++j;
//       if(j >= size_arr2) {
//         return sum;
//       } 
//     }
//     sum += arr1[i] + arr2[j];
//     ++i;
//     ++j;
//   }
//   return sum;
// }

/*
  let zip_flat_flat :(int array code * int array code) -> int code
  = C.to_code2 @@ fun (arr1, arr2) ->
    zip_with C.( + )
      (of_arr arr1 |> 
        flat_map (fun x -> of_arr arr2 |> map C.(fun y -> x * y)))
      (of_arr arr2 |> 
        flat_map (fun x -> of_arr arr1 |> map C.(fun y -> x - y)))
    |> take (C.int 20_000_000)
    |> fold C.(+) C.(int 0)
*/
int64_t zip_flat_flat(const int64_t arr1[], const int64_t size_arr1, const int64_t arr2[], const int64_t size_arr2) {
  int64_t sum = 0;
  int i1, i2, j1, j2, taken;
  const int to_take = 200000000;
  i2 = 0;
  j2 = 0;
  taken = 0;
  for(i1=0; i1<size_arr1 && taken<to_take; ++i1) {
    for(j1=0; j1<size_arr2; ++j1) {
      if(taken >= to_take) {
        return sum;
      }

      if(i2 >= size_arr1) {
        ++j2;
        if(j2 >= size_arr2) {
          return sum;
        } 
        i2 = 0;
      }

      const int64_t t1 = arr1[i1] * arr2[j1];
      const int64_t t2 = arr2[j2] - arr1[i2];
      sum += t1 + t2;
      ++taken;
      ++i2;
    }
  }
  return sum;
}

int64_t decoding(const int64_t arr1[], const int64_t size_arr1, const int64_t arr2[], const int64_t size_arr2) {
  int64_t sum = 0;
  int64_t i1, i2,// for arr1
           j1, j2;// for arr2
  j1=0; j2=0;
  for (i1=0; i1<size_arr1; ++i1) {
    const int64_t t1 = arr1[i1];
    const int64_t t = t1<254 ? t1:254;
    i2=0;
    while (i2<=t) {
      const int l = i2>=t1;
      const int64_t t2 = arr2[j1];
      if (j2<255) {
        const int r = j2>=t2;
        if (l||r) {
          ++sum;
        } 
        ++j2;
        if (j2 > t2) {
          ++j1;
          if (j1 >= size_arr2) return sum; 
          j2=0;
        }
        ++i2;
      } else {
        ++j1;
        if (j1 >= size_arr2) return sum; 
        j2=0;
      }
    }
  }
  return sum;
}
// int64_t decoding(const uint8_t arr1[], const uint64_t size_arr1, const uint8_t arr2[], const uint64_t size_arr2) {
//   int64_t sum = 0;
//   uint64_t i1, i2,// for arr1
//            j1, j2;// for arr2
//   j1=0; j2=0;
//   for (i1=0; i1<size_arr1; ++i1) {
//     const uint8_t t1 = arr1[i1];
//     const uint8_t t = t1<254 ? t1:254;
//     i2=0;
//     while (i2<=t) {
//       const int l = i2>=t1;
//       const uint8_t t2 = arr2[j1];
//       if (j2<255) {
//         const int r = j2>=t2;
//         if (l||r) {
//           ++sum;
//         } 
//         ++j2;
//         if (j2 > t2) {
//           ++j1;
//           if (j1 >= size_arr2) return sum; 
//           j2=0;
//         }
//         ++i2;
//       } else {
//         ++j1;
//         if (j1 >= size_arr2) return sum; 
//         j2=0;
//       }
//     }
//   }
//   return sum;
// }
#if defined(NOOPT)
  #pragma GCC pop_options
#endif