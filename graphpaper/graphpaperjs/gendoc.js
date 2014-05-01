//
//  Copyright (c) 2014, Warren Weckesser
//  All rights reserved.
//

colormap = {
    "Black":        [0, 0, 0],
    "Gray":         [128, 128, 128],
    "Light Gray":   [192, 192, 192],
    "Red":          [255, 0, 0],
    "Green":        [0, 255, 0],
    "Blue":         [0, 0, 255],
    "Cyan":         [0, 255, 255],
    "Magenta":      [255, 0, 255],
    "Yellow":       [255, 255, 0],
    "Dark Red":     [128, 0, 0],
    "Dark Green":   [0, 128, 0],
    "Dark Blue":    [0, 0, 128],
    "Dark Cyan":    [0, 128, 128],
    "Dark Magenta": [128, 0, 128],
    "Dark Yellow":  [128, 128, 0]
};

//
// Map paper_format string to [width, height] in cm.
//
paper_format_map = {
    "letter": [8.5*2.54, 11*2.54],
    "legal": [8.5*2.54, 14*2.54],
    "a3": [29.7, 42.0],
    "a4": [21.0, 29.7],
    "a5": [14.85, 21.0]
};

function width_height_cm(paper_format, orientation) {
    var paper_width;
    var paper_height;

    var paper_dim = paper_format_map[paper_format];
    if (orientation == "portrait") {
        paper_width = paper_dim[0];
        paper_height = paper_dim[1];
    }
    else {
        paper_width = paper_dim[1];
        paper_height = paper_dim[0];
    }
    return [paper_width, paper_height];
}


function add_props(doc) {
    doc.setProperties({
            title: 'Graph Paper',
            author: 'Graph Paper Generator by Warren Weckesser',
            keywords: 'graph paper',
            creator: 'Graph Paper Generator by Warren Weckesser'
    });
}


function graphpaper(paper_format, orientation, grid_spacing, border_size, color_rgb,
                    line_width, heavier_lines) {
    var paper_dim = width_height_cm(paper_format, orientation);

    var paper_width = paper_dim[0];
    var paper_height = paper_dim[1];

    //
    // Compute the horizontal and vertical grid sizes.
    //
    var hgrid = Math.floor((paper_width - 2*border_size) / grid_spacing);
    var vgrid = Math.floor((paper_height - 2*border_size) / grid_spacing);

    //
    // If heavier lines will be drawn, we adjust hgrid and vgrid to
    // be multiples of heavier_lines.  Then the outer most grid lines
    // around the whole grid will be heavy lines.
    //
    if (heavier_lines > 0) {
        hgrid = heavier_lines * Math.floor(hgrid / heavier_lines);
        vgrid = heavier_lines * Math.floor(vgrid / heavier_lines);
    }

    //
    // These are the actual width and height of the grid.
    //
    var actual_graph_width = hgrid * grid_spacing;
    var actual_graph_height = vgrid * grid_spacing;

    var doc = new jsPDF(orientation, "cm", paper_format);

    var hborder_size = 0.5 * (paper_width - actual_graph_width);
    var vborder_size = 0.5 * (paper_height - actual_graph_height);

    doc.setDrawColor(color_rgb[0], color_rgb[1], color_rgb[2]);
    doc.setFillColor(color_rgb[0], color_rgb[1], color_rgb[2]);
    doc.setLineJoin(0);

    var heavy_line_width = 2.5 * line_width;
    //
    // Draw the outer edges using doc.rect
    //
    if (heavier_lines > 0) {
        doc.setLineWidth(heavy_line_width);
    }
    else {
        doc.setLineWidth(line_width);
    }
    doc.rect(hborder_size, vborder_size, actual_graph_width, actual_graph_height);

    //
    // Draw the vertical lines
    //
    for (var i = 1; i < hgrid; ++i) {
        if (heavier_lines > 0 && i % heavier_lines == 0) {
            doc.setLineWidth(heavy_line_width);
        }
        else {
            doc.setLineWidth(line_width);
        }

        var x = i * grid_spacing + hborder_size;
        doc.line(x, vborder_size, x, vborder_size + actual_graph_height);
    }

    //
    // Draw the horizontal lines
    //
    for (var i = 1; i < vgrid; ++i) {
        if (heavier_lines > 0 && i % heavier_lines == 0) {
            doc.setLineWidth(heavy_line_width);
        }
        else {
            doc.setLineWidth(line_width);
        }

        var y = i * grid_spacing + vborder_size;

        doc.line(hborder_size, y, hborder_size + actual_graph_width, y);
    }

    add_props(doc);
    doc.save('Test.pdf');
}


function dots_squaregrid(paper_format, orientation, grid_spacing, border_size,
                         color_rgb, line_width)
{
    var paper_dim = width_height_cm(paper_format, orientation);

    var paper_width = paper_dim[0];
    var paper_height = paper_dim[1];

    //
    // Compute the horizontal and vertical grid sizes.
    //
    var hgrid = Math.floor((paper_width - 2*border_size) / grid_spacing);
    var vgrid = Math.floor((paper_height - 2*border_size) / grid_spacing);

    //
    // These are the actual width and height of the grid.
    //
    var actual_graph_width = hgrid * grid_spacing;
    var actual_graph_height = vgrid * grid_spacing;

    var doc = new jsPDF(orientation, "cm", paper_format);

    var hborder_size = 0.5 * (paper_width - actual_graph_width);
    var vborder_size = 0.5 * (paper_height - actual_graph_height);

    doc.setDrawColor(color_rgb[0], color_rgb[1], color_rgb[2]);
    doc.setFillColor(color_rgb[0], color_rgb[1], color_rgb[2]);
    doc.setLineJoin(0);

    //
    // If we are not filling the page, we move the origin so that
    // the grid is centered.
    //
    var hoffset = (paper_width - actual_graph_width) / 2.0;
    var voffset = (paper_height - actual_graph_height) / 2.0;

    //
    // Draw the dots
    //
    for (i = 0; i < hgrid + 1; ++i) {
        for (j = 0; j < vgrid + 1; ++j) {
            var x = i * grid_spacing;
            var y = j * grid_spacing;
            doc.circle(hoffset + x, voffset + y, line_width, 'F');
        }
    }

    add_props(doc);
    doc.save('Test.pdf');
}


function hexagonal(paper_format, orientation, grid_spacing, border_size, color_rgb,
                    line_width)
{
    var sqrt3 = Math.sqrt(3.0);

    var paper_dim = width_height_cm(paper_format, orientation);

    var paper_width = paper_dim[0];
    var paper_height = paper_dim[1];

    var doc = new jsPDF(orientation, "cm", paper_format);

    //
    // Adjust hgrid and vgrid to provide a border of width at least the
    // size of border_size.
    //
    var uwidth = paper_width - 2 * border_size;
    var uheight = paper_height - 2 * border_size;

    var hgrid = Math.floor(uwidth / grid_spacing);
    var vgrid = Math.floor((uheight - grid_spacing/(2*sqrt3)) * 2*sqrt3 / (3*grid_spacing));

    //
    // These are the actual width and height of the grid.
    //
    var actual_graph_width = hgrid * grid_spacing;
    var actual_graph_height = (1.5*vgrid + 0.5) * grid_spacing / sqrt3;
    //
    // Translate the coordinates so that the origin is at the center
    // of the lower left hexagon.
    //
    var hoffset = (paper_width - actual_graph_width)/2.0 + grid_spacing/2.0;
    var voffset = (paper_height - actual_graph_height)/2.0 + grid_spacing/sqrt3;

    doc.setDrawColor(color_rgb[0], color_rgb[1], color_rgb[2]);
    doc.setFillColor(color_rgb[0], color_rgb[1], color_rgb[2]);
    doc.setLineJoin(0);
    doc.setLineWidth(line_width);

    var d = grid_spacing;

    //
    //  Draw the outer border with a single call to doc.lines().
    //  This allows the corners to be joined with the "miter" style.
    //
    var border_lines = new Array

    for (var i = 0; i < hgrid; ++i) {
        var xc = i * d;
        border_lines[border_lines.length] = [d/2., -sqrt3*d/6.];
        border_lines[border_lines.length] = [d/2., sqrt3*d/6.];
    }
    for (var j = 0; j < vgrid; ++j) {
        border_lines[border_lines.length] = [0, d/sqrt3];
        if (j % 2 == 0) {
            border_lines[border_lines.length] = [-d/2., sqrt3*d/6.];
        }
        else if (j != vgrid-1) {
            border_lines[border_lines.length] = [d/2., sqrt3*d/6.];            
        }
    }
    if (vgrid % 2 == 1)
        border_lines[border_lines.length] = [-d/2., -sqrt3*d/6];
    for (var i = hgrid-1; i > 0; --i) {
        border_lines[border_lines.length] = [-d/2., sqrt3*d/6];
        border_lines[border_lines.length] = [-d/2., -sqrt3*d/6];
    }
    for (var j = vgrid - 1; j > 0; --j) {
        border_lines[border_lines.length] = [0, -d/sqrt3];
        if (j % 2 == 1) {
            border_lines[border_lines.length] = [-d/2., -sqrt3*d/6.];
        }
        else {
            border_lines[border_lines.length] = [d/2., -sqrt3*d/6.];                
        }
    }

    //
    // Draw the interior zig-zag "horiztonal" lines.
    // Each zig-zag line across the page is draw with a single call
    // to doc.lines().
    //
    var xstart = hoffset - d/2.;
    var ystart = voffset - sqrt3*d/6.;
    doc.lines(border_lines, xstart, ystart, undefined, undefined, true);

    xstart = hoffset;

    for (var j = 0; j < vgrid - 1; ++j) {
        border_lines = [];
        var sgn;
        sgn = (j % 2 == 0) ? -1 : 1;
        for (var i = 0; i < hgrid - 1; ++i) {
            border_lines[border_lines.length] = [d/2., sgn*sqrt3*d/6];
            border_lines[border_lines.length] = [d/2., -sgn*sqrt3*d/6]       
        }
        ystart = voffset + (1 + 3*Math.floor(j / 2)) * d / sqrt3;
        if (j % 2 == 1) {
            ystart += d / sqrt3;
        }
        doc.lines(border_lines, xstart, ystart);
    }

    //
    // Draw the interior vertical edges.
    //
    for (var j = 0; j < vgrid; ++j) {
        m = hgrid - 1;
        if (j % 2 == 1) {
            m = m - 1;
        }
        for (var i = 0; i < m; ++i) {
            var x = hoffset + (0.5 + i) * d;
            var y = voffset + (3*j - 1)*d/sqrt3/2;
            if (j % 2 == 0) {
                doc.line(x, y, x, y + d/sqrt3);
            }
            else {
                doc.line(x + d/2, y, x + d/2, y + d/sqrt3);
            }
        }
    }

    add_props(doc);
    doc.save('Test.pdf');
}


function generatePDF()
{
    //
    // Get the options from the form.
    //
    var pattern_select = document.getElementById("pattern");
    var pattern = pattern_select.options[pattern_select.selectedIndex].value.split(" ", 1);

    var color_select = document.getElementById("color");
    var colorname = color_select.options[color_select.selectedIndex].value;
    var color = colormap[colorname];

    var paper_format_select = document.getElementById("papersize");
    var paper_format = paper_format_select.options[paper_format_select.selectedIndex].value.toLowerCase();

    var orientation_select = document.getElementById("orientation");
    var orientation = orientation_select.options[orientation_select.selectedIndex].value.toLowerCase();

    var grid_spacing_select = document.getElementById("gridspacing");
    var grid_spacing_str = grid_spacing_select.options[grid_spacing_select.selectedIndex].value;
    var grid_terms = grid_spacing_str.split(" ");
    var grid_spacing = 1.0*grid_terms[0];
    if (grid_terms[1] == "in") {
        // Convert to cm.
        grid_spacing *= 2.54;
    }

    var border_size_select = document.getElementById("bordersize");
    var border_size_str = border_size_select.options[border_size_select.selectedIndex].value;
    var border_terms = border_size_str.split(" ");
    var border_size = 1.0*border_terms[0];
    if (border_terms[1] == "in") {
        // Convert to cm.
        border_size *= 2.54;
    }

    var line_width_select = document.getElementById("linewidth");
    var line_width_str = line_width_select.options[line_width_select.selectedIndex].value;
    var line_width_terms = line_width_str.split(" ");
    // Convert the value from pts to cm.
    var line_width = 2.54*(1.0*line_width_terms[0] / 72.0);

    var heavier_lines_select = document.getElementById("heavierlines");
    var heavier_lines = heavier_lines_select.options[heavier_lines_select.selectedIndex].value;
    if (heavier_lines == "None") {
        heavier_lines = 0;
    }
    else {
        heavier_lines = 1 * heavier_lines;
    }
    // Convert the value from pts to cm.
    var line_width = 2.54*(1.0*line_width_terms[0] / 72.0);

    if (pattern == "Hexagonal") {
        hexagonal(paper_format, orientation, grid_spacing, border_size, color,
                  line_width);
    }
    else if (pattern == "Square") {
        graphpaper(paper_format, orientation, grid_spacing, border_size,
                   color, line_width, heavier_lines);
    }
    else {
        dots_squaregrid(paper_format, orientation, grid_spacing, border_size,
                        color, line_width);
    }
}
