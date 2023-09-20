>,----------[---------->+<]>---.    # Read first digit and subtract ASCII '0'
>,----------[---------->+<]>---.    # Read second digit and subtract ASCII '0'
<[-<+>>+>-]<[                    # Loop to multiply #1 by #2
  -                               # Decrease #2
  <[->+>+<<]                      # Copy #1 to #3
  >>[-<<+>>]                      # Restore #2
  >[-<+<<+>>>]<                  # Move #3 to #1 and restore #2
]
<<+++++++++++++++++++++++++++++++++.  # Add ASCII '0' and print the result
