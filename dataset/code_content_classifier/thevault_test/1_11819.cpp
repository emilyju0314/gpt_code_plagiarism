gl_stdimage_program make_stdimage_program() {
    string _header =
        R"(
        #version 330

        float pi = 3.14159265;

        uniform vec2 offset;
        uniform vec2 win_size;
        uniform float zoom;

        uniform sampler2D img;

        )";

    string _vert =
        R"(
        layout(location = 0) in vec2 vert_texcoord;

        out vec2 texcoord;

        void main() {
            vec2 size = textureSize(img, 0).xy;
            texcoord = vert_texcoord.xy;
            vec2 pos = offset + size * vert_texcoord.xy * zoom;
            vec2 upos = 2 * pos / win_size - vec2(1,1);
            upos.y = - upos.y;
            gl_Position = vec4(upos.x, upos.y, 0, 1);
        }

        )";

    string _frag_tonemap =
        R"(
        struct Tonemap {
            bool filmic;
            float exposure;
            float gamma;
        };
        uniform Tonemap tonemap;

        vec3 eval_filmic(vec3 x) {
            float a = 2.51f;
            float b = 0.03f;
            float c = 2.43f;
            float d = 0.59f;
            float e = 0.14f;
            return clamp((x*(a*x+b))/(x*(c*x+d)+e),0,1);
        }

        vec3 eval_tonemap(vec3 c) {
            // final color correction
            c = c*pow(2,tonemap.exposure);
            if(tonemap.filmic) {
                c = eval_filmic(c);
            } else {
                c = pow(c,vec3(1/tonemap.gamma));
            }
            return c;
        }

        )";

    string _frag_main =
        R"(
        in vec2 texcoord;
        out vec4 color;

        void main() {
            vec4 c = texture(img,texcoord);
            c.xyz = eval_tonemap(c.xyz);
            color = c;
        }
        )";

    auto prog = gl_stdimage_program();
    prog._prog =
        make_program(_header + _vert, _header + _frag_tonemap + _frag_main);

    prog._vbo = make_vertex_buffer(
        vector<vec2f>{{0, 0}, {0, 1}, {1, 1}, {1, 0}}, false);
    prog._ebo = make_element_buffer(vector<vec3i>{{0, 1, 2}, {0, 2, 3}}, false);
    return prog;
  }