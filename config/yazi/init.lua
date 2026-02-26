require("yaziline"):setup({
  color = "#81a1c1",
  secondary_color = "#2e3440",
  default_files_color = "darkgray", -- color of the file counter when it's inactive
  selected_files_color = "white",
  yanked_files_color = "green",
  cut_files_color = "red",

  separator_style = "angly", -- "angly" | "curvy" | "liney" | "empty"
  separator_open = "",
  separator_close = "",
  separator_open_thin = "",
  separator_close_thin = "",
  separator_head = "",
  separator_tail = "",

  select_symbol = "",
  yank_symbol = "󰆐",

  filename_max_length = 24, -- truncate when filename > 24
  filename_truncate_length = 6, -- leave 6 chars on both sides
  filename_truncate_separator = "..."
})

require("git"):setup()

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
    style_normal = {
        fg = "white",
        bg = "#81a1c1"
    },

    -- Usage bar style
    --   fg: Bar colour (String like "blue", or hex like "#0000ff")
    --   bg: Bar background colour (Same format as fg)
    -- Example: style_normal = { fg = "blue", bg = "black" },
    -- Default: {}

    -- Usage bar style when the used space is above the warning threshold
    -- Options are the same as style_normal
    -- Default: {}
    style_warning = {}
})

require("full-border"):setup {
	-- Available values: ui.Border.PLAIN, ui.Border.ROUNDED
	type = ui.Border.ROUNDED,
}
