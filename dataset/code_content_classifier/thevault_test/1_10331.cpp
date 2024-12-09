static bool write_file(const char* filepath, const char* data, const char* cvar,
    bool append = false, int binary_size = -1)
{
    sx_file_writer writer;
    if (!sx_file_open_writer(&writer, filepath, append ? SX_FILE_OPEN_APPEND : 0))
        return false;

    if (cvar && cvar[0]) {
        const int items_per_line = 8;

        // .C file
        if (!append) {
            // file header
            char header[512];
            sx_snprintf(header, sizeof(header),
                "// This file is automatically created by glslcc v%d.%d.%d\n"
                "// http://www.github.com/septag/glslcc\n"
                "// \n"
                "#pragma once\n\n",
                VERSION_MAJOR, VERSION_MINOR, VERSION_SUB);
            sx_file_write_text(&writer, header);
        }

        char var[128];
        int len;
        int char_offset = 0;
        char hex[32];

        if (binary_size > 0)
            len = binary_size;
        else
            len = sx_strlen(data) + 1; // include the '\0' at the end to null-terminate the string

        // align data to uint32_t (4)
        const uint32_t* aligned_data = (const uint32_t*)data;
        int aligned_len = sx_align_mask(len, 3);
        if (aligned_len > len) {
            uint32_t* tmp = (uint32_t*)sx_malloc(g_alloc, aligned_len);
            if (!tmp) {
                sx_out_of_memory();
                return false;
            }
            sx_memcpy(tmp, data, len);
            sx_memset((uint8_t*)tmp + len, 0x0, aligned_len - len);
            aligned_data = tmp;
        }
        const char* aligned_ptr = (const char*)aligned_data;

        sx_snprintf(var, sizeof(var), "static const unsigned int %s_size = %d;\n", cvar, len);
        sx_file_write_text(&writer, var);
        sx_snprintf(var, sizeof(var), "static const unsigned int %s_data[%d/4] = {\n\t", cvar, aligned_len);
        sx_file_write_text(&writer, var);

        sx_assert(aligned_len % sizeof(uint32_t) == 0);
        int uint_count = aligned_len / 4;
        for (int i = 0; i < uint_count; i++) {
            if (i != uint_count - 1) {
                sx_snprintf(hex, sizeof(hex), "0x%08x, ", *aligned_data);
            } else {
                sx_snprintf(hex, sizeof(hex), "0x%08x };\n", *aligned_data);
            }
            sx_file_write_text(&writer, hex);

            ++char_offset;
            if (char_offset == items_per_line) {
                sx_file_write_text(&writer, "\n\t");
                char_offset = 0;
            }

            ++aligned_data;
        }

        sx_file_write_text(&writer, "\n");

        if (aligned_ptr != data) {
            sx_free(g_alloc, const_cast<char*>(aligned_ptr));
        }
    } else {
        if (binary_size > 0)
            sx_file_write(&writer, data, binary_size);
        else
            sx_file_write(&writer, data, sx_strlen(data));
    }

    sx_file_close_writer(&writer);
    return true;
}