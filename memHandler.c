#include "shell.h"

char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void freeData(data_t *data);
void freeSarray(char **arr, int size);

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
 * _realloc - reallocate a memory block
 * @ptr: prev pointer
 * @old_size: prev size
 * @new_size: new size
 * Return: new pointer | NULL (failed)
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p, *cp = ptr;
	unsigned int i, min;

	if (old_size == new_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	min = old_size < new_size ? old_size : new_size;

	p = malloc(new_size);
	if (p == NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size != old_size && ptr != NULL)
	{
		for (i = 0; i < min; i++)
			p[i] = cp[i];
		free(ptr);
	}

	return (p);
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
	data->cmd = NULL;

	/** free data->lineptr*/
	free(data->lineptr);
	data->lineptr = NULL;

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
