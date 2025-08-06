/* 
The [[fallthrough]] attribute is used to indicate that a fall-through in a switch
statement is intentional and that a compiler warning should not be issued.
*/
void f(int n)
{
     void g(), h(), i();

     switch (n)
     {
     case 1:
     case 2:
          // For n = 1 or n = 2, g() is called.
          g();
          // The [[fallthrough]] attribute indicates that the fall-through to the next case is intentional.
          // Without this, a compiler might warn about an implicit fall-through.
          [[fallthrough]];
     case 3:
          // Execution falls through from case 2 to here.
          // For n = 3 (or n=1, n=2), h() is called.
          h();
          // Note: There is an implicit fall-through here to case 4.
          // A compiler might issue a warning for this, as it's not explicitly marked with [[fallthrough]].
     case 4:
          // For n = 4, or if fall-through occurs from case 3.
          if (n < 3)
          {
               i();
               // This is a valid use of [[fallthrough]]. It's inside a statement,
               // and it's the last statement before the next case label.
               [[fallthrough]]; // OK
          }
          else
          {
               // If n is not less than 3, the function returns.
               return;
          }
     case 5:
          // This will cause a compilation error.
          // The [[fallthrough]] attribute must be followed by a case or default label.
          // Since case 5 is the last case, there is nowhere to fall through to.
          [[fallthrough]]; // ill-formed, no subsequent case or default label
     }
}