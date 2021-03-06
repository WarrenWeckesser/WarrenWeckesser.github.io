/*
 *  lorenz_solverdemo.js
 *
 *  This file was generated by the program VFGEN, version: 2.5.0-dev
 *  Generated on 14-May-2014 at 21:03
 */


var state = [1.0,0.0,1.0]
var t = 0.0
var intervalID = "none"

function clear_canvas()
 {
    var ctx = document.getElementById('canvas').getContext('2d')
    ctx.clearRect(0,0,500,500)
 }

function init()
 {
    clear_canvas()
    t = 0.0
    x0 = parseFloat(document.getElementById('x0').value)
    y0 = parseFloat(document.getElementById('y0').value)
    z0 = parseFloat(document.getElementById('z0').value)
    state[0] = x0
    state[1] = y0
    state[2] = z0
    document.getElementById('x_t').value = document.getElementById('x0').value
    document.getElementById('y_t').value = document.getElementById('y0').value
    document.getElementById('z_t').value = document.getElementById('z0').value
    document.getElementById('t').value = t
 }

function start_animation()
 {
    if (intervalID == "none") {
        intervalID = setInterval(advance,0)
    }
 }

function stop_animation()
{
    if (intervalID != "none") {
        clearInterval(intervalID)
        intervalID = "none"
    }
}

function pw6(x)
{
    var x1 = x-6*Math.floor(x/6.0)
    if (x1 < 1.0) {
        return x1
    }
    if (x1 < 3.0) {
        return 1.0
    }
    if (x1 < 4.0) {
        return 1.0-(x1-3.0)
    }
    return 0.0
}

function displayX()
{
    return document.getElementById('x_xscale').value*state[0] + document.getElementById('y_xscale').value*state[1] + document.getElementById('z_xscale').value*state[2] + 1.0*document.getElementById('xoffset').value
}

function displayY()
{
    return - document.getElementById('x_yscale').value*state[0] - document.getElementById('y_yscale').value*state[1] - document.getElementById('z_yscale').value*state[2] - document.getElementById('yoffset').value
}

function advance()
{
    var params = [parseFloat(document.getElementById('sigma_value').value),parseFloat(document.getElementById('rho_value').value),parseFloat(document.getElementById('beta_value').value)]
    var numsteps = parseInt(document.getElementById('numsteps').value)
    var stoptime = parseFloat(document.getElementById('stoptime').value)
    var tol = parseFloat(document.getElementById('tolerance').value)
    var hmax = parseFloat(document.getElementById('hmax').value)
    var palette_black      = document.getElementById('black').checked
    var palette_blue_green = document.getElementById('blue+green').checked
    var palette_black_red  = document.getElementById('black+red').checked
    var ctx = document.getElementById('canvas').getContext('2d')
    ctx.save()
    ctx.translate(250,250)
    ctx.beginPath()
    if (palette_black) {
        var red = 0.0
        var green = 0.0
        var blue = 0.0
    }
    else if (palette_blue_green) {
        var red = 0.0
        var green = 255*pw6(t)
        var blue = 255*pw6(t+7.0)
    }
    else if (palette_black_red) {
        var red = 255*pw6(t)
        var green = 0.0
        var blue = 0.0
    }
    ctx.strokeStyle = "rgb("+parseInt(red)+","+parseInt(green)+","+parseInt(blue)+")"
    ctx.moveTo(displayX(),displayY())
    for (var i = 0; i < numsteps; ++i) {
        var Xderiv = lorenz_derivs7(state,params)
        var m = 0.0
        for (var j = 0; j < 3; ++j) {
            var a = Xderiv[6][j]
            m += a*a
        }
        m = Math.sqrt(m)/5040.0
        var stepsize = Math.min(hmax,Math.pow(tol/m,0.142857))
        if (t + stepsize > stoptime) {
            stepsize = stoptime - t
        }
        state = lorenz_evaltaylor7(stepsize,state,Xderiv)
        t += stepsize
        ctx.lineTo(displayX(),displayY())
        if (t >= stoptime) {
            stop_animation()
            break
        }
    }
    ctx.stroke()
    ctx.restore()
    document.getElementById('x_t').value = state[0]
    document.getElementById('y_t').value = state[1]
    document.getElementById('z_t').value = state[2]
    document.getElementById('t').value = t
}
