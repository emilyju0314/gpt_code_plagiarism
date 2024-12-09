void Freq_Distructor(struct Freq* freq)
{
	freq->prev->next = NULL;
	struct Freq* freq_next = freq->next;
	struct Freq* tmp = NULL;

	free(freq);

	while (freq_next != NULL)
	{
		tmp = freq_next->next;
		free(freq_next);
		freq_next = tmp;
	}
}