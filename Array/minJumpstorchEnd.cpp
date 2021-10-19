// int minJumps(int A[], int n)
// {
//     int jumps = 0, curEnd = 0, curFarthest = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (i > curFarthest)
//             return -1;
//         curFarthest = max(curFarthest, i + A[i]);
//         if (i < n - 1 && i == curEnd)
//         {
//             jumps++;
//             curEnd = curFarthest;
//         }
//     }
//     return jumps;
// }