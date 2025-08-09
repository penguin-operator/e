include io.{stdout, write}, string.replace;
[]u8 code = "include io.{stdout, write}, string.replace;\n[]u8 code = ?;\ncode::replace(63, code);\nstdout::write(code);\n";
code::replace(63, code);
stdout::write(code);
