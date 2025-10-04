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
