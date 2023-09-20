>,------------------------------------------------ # Read first digit into #1
>,------------------------------------------------ # Read second digit into #2
[                          # Loop to multiply #1 by #2
  <[>>+<<<+>-]>>[<<+>>-]   # COPY #1 INTO #3 AND #0, THEN COPY #3 BACK TO #1
  <-                      # MOVE TO #0 AND DECREASE BY ASCII '0' (DEC 48)
]
<<++++++++++++++++++++++++++++++++++++++++++++++++ # Print the result
