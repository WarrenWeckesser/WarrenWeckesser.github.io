#
# plot_pendulumv_solution.R
#
# Uses the vector field defined in pendulumv.R.
# The root-finding ability of the ode function in the deSolve
# package is used to identify the points where the velocity
# is zero.
#

library(deSolve)

# Load the pendulum vector field definition.
source("pendulumv.R")

# Define a dummy event function.  We're only interested
# recording the roots of the function pendulumv_v.
event <- function(t, y, parms) {
	return(y)
}

# Parameters
parameters = c(g = 9.81, b = 0.25, L = 1.0, m = 1.0)

# Initial conditions
state = c(theta = 3.14, v = 0.0)

# Time values
times = seq(0, 10, by = 0.02)

# Call the ODE solver
sol = ode(y = state, times = times, func = pendulumv, parms = parameters,
          jactype = "fullusr", jacfunc = pendulumv_jac,
          atol = 1e-8, rtol = 1e-6, method = "lsoda",
          events = list(func = event, root = TRUE),
          rootfunc = pendulumv_v)

troot <- attr(sol, "troot")
theta_root <- attr(sol, "valroot")[1,]

# Plot the solution to a PNG file.
png(file = "plot_pendulumv_solution.png")
par(mfcol = c(2,1), mar = c(4, 4.5, 2, 2), oma = c(1, 0, 1, 0), cex = 1.1)
plot(sol[, "time"], sol[, "theta"],
     xlab = "t", ylab = "theta", main = "Pendulum Solution",
     type = "l", col = "blue")
points(troot, theta_root, pch = 19, col = "black", cex = 1)
plot(sol[, "time"], pendulumv_sol_energy(sol, parameters),
     xlab = "t", ylab = "energy",
     type="l", col = "red")
dev.off()
