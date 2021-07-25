# Adding directional focus do dwm

So i came accross this problem of having to iterate the stack to reach to a window, for example with the following layout of windows
```
|        |   c2    |
|        |_______  |
|   c1   +   c3    |
|        |_______  |
|        |   c4    |
```

If i want to **c3 -> c1** i must do **c3 -> c2 -> c1**. 

So i made some little functions to give directional focus rather and do **c3 -> c1 directly**.

## What to have in consideration

- Just works for the current monitor, not jumping for the other monitors
  - Might consider adding if asked   
- Does not consider floating windows as part of the decision
- Tested only with default layout

Bind as shown below in your **config.h**
```

-- snip --

{ MODKEY,                       XK_Right,  focusright,     {0} },
{ MODKEY,                       XK_Left,   focusleft,      {0} },
{ MODKEY,                       XK_Down,   focusdown,      {0} },
{ MODKEY,                       XK_Up,     focusup,        {0} },

-- snip -- 


```
