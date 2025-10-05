#pragma once
#include <godot_cpp/classes/resource.hpp>

namespace godot {

    class OtherClass : public Resource {
        GDCLASS(OtherClass, Resource)

        private:
            String word;
            int val;
        
        protected:
            static void _bind_methods();

        public:
            OtherClass();
            ~OtherClass();

            void set_word(const String p_word);
            String get_word() const;
            void set_val(const int p_val);
            int get_val() const;
    };
}
