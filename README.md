# What to have in consideration

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
