# What to have in consideration

- Just works for the current monitor, not jumping for the other monitors
  - Might consider adding if asked   
- Does not consider floating windows as part of the decision

Tested with:
- tiled
- floating
- Fibonnacci (spiral and dwindle)
- Gapless grid


Binds ar made as shown below in (using arrows), if you want vim shortcuts, modify it accordingly :) 
```
-- snip --

{ MODKEY,                       XK_Right,  focusright,     {0} },
{ MODKEY,                       XK_Left,   focusleft,      {0} },
{ MODKEY,                       XK_Down,   focusdown,      {0} },
{ MODKEY,                       XK_Up,     focusup,        {0} },

-- snip -- 
```

