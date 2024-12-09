AZStd::size_t hash_next_bucket_size(AZStd::size_t n)
    {
        const AZStd::size_t* first = prime_list;
        const AZStd::size_t* last =  prime_list + AZ_ARRAY_SIZE(prime_list);
        const AZStd::size_t* pos = AZStd::lower_bound(first, last, n);
        return (pos == last ? *(last - 1) : *pos);
    }