static auto compare_fat_write_time(os::chrono::time_point First, os::chrono::time_point Second)
{
	if (!compare_numbers(to_fat_write_time(First), to_fat_write_time(Second)))
		return 0;

	if (!compare_numbers(to_whole_seconds(First), to_whole_seconds(Second)))
		return 0;

	return compare_time(First, Second);
}