# gdextension-cpp-example

This follows the following tutorial:

https://docs.godotengine.org/en/stable/tutorials/scripting/cpp/gdextension_cpp_example.html

## Project Structure

```
.
├── demo        - Godot project
├── godot-cpp   - C++ bindings
└── src         - extension source code
```

## Compiling

See: https://docs.godotengine.org/en/stable/tutorials/scripting/cpp/gdextension_cpp_example.html#compiling-the-plugin

```
scons platform=macos
```

## Next steps

- [x] - [Adding Properties](https://docs.godotengine.org/en/stable/tutorials/scripting/cpp/gdextension_cpp_example.html#adding-properties)
- [ ] - [Signals](https://docs.godotengine.org/en/stable/tutorials/scripting/cpp/gdextension_cpp_example.html#signals)


## Steps Taken, Hangups, and Pitfalls

**Installing PIP**

- Turns out, `pip` was already installed on my system, just needed to run `python3 pip <args>` instead of `pip <args>`

**Installing SConstruct**

- Pretty straightforward with the `pip` installer
- I later learned I could have just used `brew install scons`, but maybe pip is better anyways

**Building Godot C++ Bindings**

The Godot executable can also be used as a command line binary. I aliased `godot` to the `Godot` binary path (NOT application; macos applications are just directories).

I tried running `godot --dump-extension-api` against godot-mono, but it failed, complaining about not being able to find the .NET v8 runtime or something. Since the whole reason I'm researching godot-cpp is to be able to write efficient mesh generation code and deploy it to the web (since the opensource webassembly compiler that Godot uses does not support C#), I just used the plain `godot` binary instead. It worked just fine.

In `gdexample.cpp`, I don't understand how `sin` and `cos` are getting called without including `<cmath>` or `"math.h"`.

**ClassDB::bind_method**

AI told me:

> ClassDB::bind_method in Godot is a static function used in C++ GDExtensions to expose methods of your custom C++ classes to the Godot engine, making them callable from GDScript and accessible within the editor.

So, it seems that C++ classes can be used directly in GDScript!! Hell yea.

Confirmed - this custom modules tutorial explicitly shows adding C++ methods being used in GDScript:

- https://docs.godotengine.org/en/3.5/development/cpp/custom_modules_in_cpp.html


**Arrays in C++**

Arrays in C++ are very similar to C# arrays. One of the main caveats I ran into was getting the array length. `sizeof(arr)` did not produce the array length as I expected. Instead, you need to use the following to get the array length:

```
sizeof(ARRAY_TEST) / sizeof(ARRAY_TEST[0])
```

This is because iterating over an array is just changing the offest from the beginning pointer. [sizeof(var)](https://www.geeksforgeeks.org/cpp/cpp-sizeof-operator/) returns the number of bytes that that variable contains. Since an `int` has 32 bits (4 bytes), then `sizeof(arr)` for an array of ints produces a number 4X larger than expected!

Getting the size of an array of tuples proves to be quite the challenge, and is one more reason to prefer the more simple 1-dimensional array approach.


**Tuples in C++**

Declaring a tuple in C++ is straightforward, albeit a little clunky. I wanted to see if it was possible to define a constant array of tuples in C++. Turns out this is possible (well, everything is "possible" in code). However, I will probably just stick to a single-dimensional array and index by groups of elements. E.g., if our TRIANGULATIONS array always has groups of 15 items each, then it is simple to iterate over the elements of each group index like so:

```c++
int group_index = 5;
for (size_t i = 0; i < 15; i++) {
    int triangulation = TRIANGULATIONS[group_index * 15 + i];
    if (triangulation < 0) break;
}
```


**Templates**

C++ templates are like generics in other languages. I found a lot of template stuff when googling how to iterate over C++ tuples.