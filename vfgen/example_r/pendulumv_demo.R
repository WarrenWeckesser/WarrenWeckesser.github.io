#
# pendulumv_demo.R
#
# R demonstration script that uses the vector field
# defined in pendulumv.R
#
# This file was generated by the program VFGEN, version: 2.5.0-dev
# Generated on 14-May-2014 at 21:04
#

library(deSolve)

# Load the vector field definition and the jacobian.
source("pendulumv.R")

Pi = pi;

# --- Parameters ---
parameters = c(
    g = 9.81,
    b = 0.2,
    L = 1.0,
    m = 1.0
)

# --- Initial conditions ---
state = c(
    theta = -0.01+Pi,
    v = 0.0
)


# --- Time values ---
times = seq(0, 10, by = 0.02)

# --- Call the ODE solver ---
sol = ode(y = state, times = times, func = pendulumv, parms = parameters,
          jactype = "fullusr", jacfunc = pendulumv_jac,
          atol = 1e-8, rtol = 1e-6)

# --- Plot the solution ---
par(mfcol = c(2, 1))
t <- sol[, "time"]
plot(t, sol[, "theta"], type = "l", col = "blue",
     xlab = "t", ylab = "theta")
plot(t, sol[, "v"], type = "l", col = "blue",
     xlab = "t", ylab = "v")
