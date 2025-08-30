require("git"):setup()

require("full-border"):setup {
	-- Available values: ui.Border.PLAIN, ui.Border.ROUNDED
	type = ui.Border.ROUNDED,
}
require("yatline"):setup({
	show_background = false,

	header_line = {
		left = {
			section_a = {},
			section_b = {},
			section_c = {},
		},
		right = {
			section_a = {},
			section_b = {},
			section_c = {},
		},
	},

	status_line = {
		left = {
			section_a = {
				{ type = "string", custom = false, name = "tab_mode" },
			},
			section_b = {
				{ type = "string", custom = false, name = "hovered_size" },
			},
			section_c = {
                {type = "string", custom = false, name = "tab_num_files"},
				{ type = "coloreds", custom = false, name = "count" },
			},
		},
		right = {
			section_a = {
				{ type = "string", custom = false, name = "cursor_position" },
			},
			section_b = {
				{ type = "string", custom = false, name = "cursor_percentage" },
			},
			section_c = {
				{ type = "string", custom = false, name = "hovered_file_extension", params = { true } },
				{ type = "coloreds", custom = false, name = "permissions" },
			},
		},
	},
})

require("fs-usage"):setup({
    -- All values are optional

    -- Position of the component
    --   parent: Parent component ("Header" or "Status")
    --   align: Anchor point within parent object ("LEFT" or "RIGHT")
    --   order: Order relative to others in the same parent
    -- Default: { parent = "Header", align = "RIGHT", order = 2000 }
    position = { parent = "Header", align = "RIGHT", order = 2000 },

    -- Text format
    -- One of:
    --   "both": Partition name and percent used
    --   "name": Only partition name
    --   "usage": Only percent used
    -- Default: "both"
    format = "both",

    -- Option to enable or disable the usage bar
    -- Default: true
    bar = true,

    -- Percent usage to use the warning style (-1 to disable)
    -- Default: 90
    warning_threshold = 90,

    -- For style options, any unset options use the progress bar style
    --   from the Yazi flavor if available, otherwise it falls back to
    --   the default Yazi style.

    -- Label text style
    --   fg: Text colour (String like "white", or hex like "#ffffff")
    --      (Can also be "" to use the reverse of the bar colour)
    --   bold: Make the label bold (bool)
    --   italic: Make the label italic (bool)
    -- Example: style_label = { fg = "", bold = true, italic = false },
    -- Default: {}
    style_label = {},

    -- Usage bar style
    --   fg: Bar colour (String like "blue", or hex like "#0000ff")
    --   bg: Bar background colour (Same format as fg)
    -- Example: style_normal = { fg = "blue", bg = "black" },
    -- Default: {}
    style_normal = {},

    -- Usage bar style when the used space is above the warning threshold
    -- Options are the same as style_normal
    -- Default: {}
    style_warning = {}
})
