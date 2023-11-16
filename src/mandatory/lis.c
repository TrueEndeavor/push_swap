/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:40:04 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/15 14:50:41 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <push_swap.h>

int	_lis(int arr[], int n, int *max_ref)
{
	int	i;
	int	res;
	int	max_ending_here;

	if (n == 1)
		return (1);

	i = 1;
	res = 1;
	max_ending_here = 1;
	while (i < n)
	{
		res = _lis(arr, i, max_ref);
		if (arr[i - 1] < arr[n - 1] && res + 1 > max_ending_here)
			max_ending_here = res + 1;
	i++;
	}
	if (*max_ref < max_ending_here)
		*max_ref = max_ending_here;
	return (max_ending_here);
}

int	lis(int arr[], int n)
{
	int	max;

	max = 1;
	_lis(arr, n, &max);
	return (max);
}

#include <stdio.h>

// Driver program to test above function
int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60, 71};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
    printf("Length of lis is %d", lis(arr, n));
    return 0;
}