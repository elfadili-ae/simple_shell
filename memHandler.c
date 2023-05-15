#include "shell.h"

/**
 * _memcpy - copy memory
 * @src: memory area to copy
 * @dest: memory arae destination
 * @n: number of bytes to copy
 * Return: pointer to memory @dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];

	return (dest);
}

/**
 * freeData -
 *
 *
 */
void freeData(data_t *data)
{
	/** free data->cmd **/
	freeSarray(data->cmd, data->cmdSize);

	/** free data->lineptr*/
	free(data->lineptr);

	/** free data->envp */

}

/**
 *
 *
 *
 *
 */
void freeSarray(char **arr, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
}
